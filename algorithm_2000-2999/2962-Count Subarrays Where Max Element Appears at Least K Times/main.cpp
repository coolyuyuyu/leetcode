class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = *std::max_element(nums.begin(), nums.end());

        long long ret = 0;
        for (int i = 0, j = 0, n = nums.size(), cnt = 0; i < n; ++i) {
            for (; j < n && cnt < k; ++j) {
                cnt += (nums[j] == mx ? 1 : 0);
            }

            if (cnt == k) {
                ret += n - j + 1;
            }

            cnt -= (nums[i] == mx ? 1 : 0);
        }

        return ret;
    }
};
