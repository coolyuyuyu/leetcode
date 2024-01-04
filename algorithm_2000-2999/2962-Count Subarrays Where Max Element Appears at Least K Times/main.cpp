class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = *std::max_element(nums.begin(), nums.end());

        long long ret = 0;
        for (int i = 0, j = 0, cnt = 0; i < n; ++i) {
            for (; j < n && cnt < k; ++j) {
                if (nums[j] == mx) {
                    ++cnt;
                }
            }

            if (cnt >= k) {
                ret += n - j + 1;
            }

            if (nums[i] == mx) {
                --cnt;
            }
        }

        return ret;
    }
};
