class Solution {
public:
    vector<int> byBucket(const vector<int>& nums, int k, int x) {
        vector<int> ret;

        vector<int> cnts(102, 0);
        auto findSmallest = [&cnts, x]() {
            int cnt = 0;
            for (int i = 0; i < 50; ++i) {
                cnt += cnts[i];
                if (x <= cnt) {
                    return i - 50;
                }
            }
            return 0;
        };
        for (int i = 0; i < nums.size(); ++i) {
            if (k <= i) {
                --cnts[nums[i - k] + 50];
            }
            ++cnts[nums[i] + 50];

            if (k <= i + 1) {
                ret.push_back(findSmallest());
            }
        }

        return ret;
    }

    vector<int> byMultiset(const vector<int>& nums, int k, int x) {
        vector<int> ret;

        multiset<int> ms1, ms2;
        auto findSmallest = [&ms1, &ms2, x]() {
            return std::min(*ms1.rbegin(), 0);
        };
        for (int i = 0; i < nums.size(); ++i) {
            if (k <= i) {
                int v = nums[i - k];
                auto itr1 = ms1.find(v);
                if (itr1 != ms1.end()) {
                    ms1.erase(itr1);
                }
                else {
                    ms2.erase(ms2.find(v));
                }

                if (ms1.size() < x && !ms2.empty()) {
                    ms1.insert(*ms2.begin());
                    ms2.erase(ms2.begin());
                }
            }
            ms1.insert(nums[i]);
            if (x < ms1.size()) {
                ms2.insert(*ms1.rbegin());
                ms1.erase(std::prev(ms1.end()));
            }

            if (k <= i + 1) {
                ret.push_back(findSmallest());
            }
        }

        return ret;
    }


    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        //return byBucket(nums, k, x);
        return byMultiset(nums, k, x);
    }
};
