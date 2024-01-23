class Solution {
public:
    vector<int> byBucket(const vector<int>& nums, int k, int x) {
        int n = nums.size();

        int cnts[101];
        std::fill(cnts, cnts + 101, 0);
        std::function<int()> findKthSmallest = [&]() {
            int cnt = 0;
            for (int i = 0; i < 50; ++i) {
                cnt += cnts[i];
                if (x <= cnt) {
                    return i - 50;
                }
            }

            return 0;
        };

        vector<int> ret(n - k + 1);
        for (int i = 0; i < n; ++i) {
            ++cnts[nums[i] + 50];

            if (i >= k - 1) {
                ret[i - k + 1] = findKthSmallest();

                --cnts[nums[i - k + 1] + 50];
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
                ret[i - k + 1] = std::min(*ms1.rbegin(), 0);

                int toErase = nums[i - k + 1];
                auto itr2 = ms2.find(toErase);
                if (itr2 != ms2.end()) {
                    ms2.erase(itr2);
                }
                else {
                    auto itr1 = ms1.find(toErase);
                    ms1.erase(itr1);
                    if (ms1.size() < k && !ms2.empty()) {
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
