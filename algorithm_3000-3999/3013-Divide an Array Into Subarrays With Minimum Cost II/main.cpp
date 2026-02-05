class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        // sliding window of len dist+1, starting from i=1 to the end, find the min sum of min k-1 nums

        int n = nums.size();
        --k;
        int len = dist + 1;

        multiset<int> ms1, ms2;
        long long sum = 0;
        long long ret = LLONG_MAX;
        for (int i = 1; i < n; ++i) {
            ms1.insert(nums[i]);
            sum += nums[i];
            if (ms1.size() > k) {
                auto itr1 = std::prev(ms1.end());
                ms2.insert(*itr1);
                sum -= *itr1;
                ms1.erase(itr1);
            }

            if (i >= len) {
                ret = std::min(ret, sum);

                int toErase = nums[i + 1 - len];
                if (ms2.find(toErase) != ms2.end()) { // in ms2
                    ms2.erase(ms2.find(toErase));
                }
                else { // in ms1
                    ms1.erase(ms1.find(toErase));
                    sum -= toErase;
                    if (!ms2.empty()) {
                        auto itr2 = ms2.begin();
                        sum += *itr2;
                        ms1.insert(*itr2);
                        ms2.erase(itr2);
                    }
                }
            }

        }

        return nums[0] + ret;
    }
};
