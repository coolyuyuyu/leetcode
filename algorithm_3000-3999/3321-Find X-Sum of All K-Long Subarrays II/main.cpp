class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();

        long long curSum = 0;
        unordered_map<int, int> cnts;
        set<pair<int, int>> topx, rest;
        std::function<void(int)> insert = [&](int num) {
            int& cnt = cnts[num];
            if (topx.find({cnt, num}) != topx.end()) {
                curSum -= 1LL * cnt * num;
                topx.erase({cnt, num});
            }
            else {
                rest.erase({cnt, num});
            }

            ++cnt;
            topx.insert({cnt, num});
            curSum += 1LL * cnt * num;

            if (topx.size() > x) {
                auto itr = topx.begin();
                curSum -= 1LL * itr->first * itr->second;
                rest.insert(*itr);
                topx.erase(itr);
            }
        };
        std::function<void(int)> remove = [&](int num) {
            int& cnt = cnts[num];
            if (topx.find({cnt, num}) != topx.end()) {
                curSum -= 1LL * cnt * num;
                topx.erase({cnt, num});
            }
            else {
                rest.erase({cnt, num});
            }

            --cnt;
            rest.insert({cnt, num});

            if (topx.size() < x && !rest.empty()) {
                auto itr = std::prev(rest.end());
                curSum += 1LL * itr->first * itr->second;
                topx.insert(*itr);
                rest.erase(itr);
            }
        };

        vector<long long> ret(n - k + 1);
        for (int i = 0; i < n; ++i) {
            insert(nums[i]);

            if (i + 1 >= k) {
                ret[i + 1 - k] = curSum;
            }

            if (i + 1 >= k) {
                remove(nums[i - k + 1]);
            }
        }

        return ret;
    }
};
