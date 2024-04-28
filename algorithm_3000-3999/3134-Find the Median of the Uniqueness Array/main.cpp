class Solution {
public:
    int medianOfUniquenessArray(vector<int>& nums) {
        int n = nums.size();
        long long total = (1LL * n * (n + 1) / 2 + 1) / 2;

        std::function<long long(int)> countSubarrDiffCntLE = [&](int target) {
            unordered_map<int, int> cnts;

            long long ret = 0;
            for (int lft = 0, rht = 0; rht < n; ++rht) {
                ++cnts[nums[rht]];
                for (; lft <= rht && cnts.size() > target; ++lft) {
                    if (--cnts[nums[lft]] == 0) {
                        cnts.erase(nums[lft]);
                    }
                }

                ret += (rht - lft + 1);
            }

            return ret;
        };

        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (countSubarrDiffCntLE(mid) >= total) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};
