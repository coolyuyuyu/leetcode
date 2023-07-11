class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        std::function<int(int)> cntSubarraysWithAtMostKDistinct = [&](int k) {
            vector<int> cnts(20000 + 1, 0);

            int ret = 0;
            for (int lft = 0, rht = 0; lft < n; ++lft) {
                for (; rht < n && (rht < lft || 0 < k || (k == 0 && 0 < cnts[nums[rht]])); ++rht) {
                    if (cnts[nums[rht]]++ == 0) {
                        --k;
                    }
                }

                ret += (rht - lft);
                
                if (--cnts[nums[lft]] == 0) {
                    ++k;
                }
            }

            return ret;
        };

        return cntSubarraysWithAtMostKDistinct(k) - cntSubarraysWithAtMostKDistinct(k - 1);
    }
};
