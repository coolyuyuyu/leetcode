class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = *std::max_element(nums.begin(), nums.end());

        long long ret = 0;
        for (int lft = 0, rht = 0, n = nums.size(), mxCnt = 0; lft < n; ++lft) {
            for (; rht < n && mxCnt < k; ++rht) {
                if (nums[rht] == mx) {
                    ++mxCnt;
                }
            }

            if (mxCnt >= k) {
                ret += n - rht + 1;
            }

            if (nums[lft] == mx) {
                --mxCnt;
            }
        }

        return ret;
    }
};
