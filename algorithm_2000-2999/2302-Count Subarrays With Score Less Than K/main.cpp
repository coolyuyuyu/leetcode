class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);

        long long presums[n + 1];
        presums[0] = 0;
        for (int i = 1; i <= n; ++i) {
            presums[i] = presums[i - 1] + nums[i];
        }

        long long ret = 0;
        for (int i = 1, j = 0; i <= n; ++i) {
            if (j < i) { j == i; }

            while (j <= n && (presums[j] - presums[i - 1]) * (j - i + 1) < k) {
                ++j;
            }

            ret += (j - i);
        }

        return ret;
    }
};
