class Solution {
public:
    vector<int> byBucket(const vector<int>& nums, int k, int x) {
        int n = nums.size();

        int cnts[102];
        std::fill(cnts, cnts + 102, 0);

        std::function<int()> findXthElement = [&]() {
            int cnt = 0;
            for (int i = 0; i < 102; ++i) {
                cnt += cnts[i];
                if (cnt >= x) {
                    return i - 50;
                }
            }

            assert(false);
            return 102;
        };

        vector<int> ret(n - k + 1);
        for (int i = 0; i < n; ++i) {
            ++cnts[nums[i] + 50];
            if (i >= k - 1) {
                ret[i + 1 - k] = std::min(findXthElement(), 0);
                --cnts[nums[i + 1 - k] + 50];
            }
        }

        return ret;
    }

    vector<int> byMultiset(const vector<int>& nums, int k, int x) {
        int n = nums.size();

        multiset<int> ms1, ms2;
        vector<int> ret(n - k + 1);
        for (int i = 0; i < n; ++i) {
            ms1.insert(nums[i]);
            if (ms1.size() > x) {
                auto itr1 = std::prev(ms1.end());
                ms2.insert(*itr1);
                ms1.erase(itr1);
            }

            if (i >= k - 1) {
                ret[i + 1 - k] = std::min(*ms1.rbegin(), 0);

                int toErased = nums[i + 1 - k];
                auto itr2 = ms2.find(toErased);
                if (itr2 != ms2.end()) {
                    ms2.erase(itr2);
                }
                else {
                    ms1.erase(ms1.find(toErased));
                    if (!ms2.empty()) {
                        itr2 = ms2.begin();
                        ms1.insert(*itr2);
                        ms2.erase(itr2);
                    }
                }
            }
        }

        return ret;
    }

    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        return byBucket(nums, k, x);
        //return byMultiset(nums, k, x);
    }
};
