class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixGcd(n);
        for (int i = 0, mx = INT_MIN; i < n; ++i) {
            mx = std::max(mx, nums[i]);
            prefixGcd[i] = std::gcd(nums[i], mx);
        }
        std::sort(prefixGcd.begin(), prefixGcd.end());

        long long ret = 0;
        for (int l = 0, r = n - 1; l < r; ++l, --r) {
            ret += std::gcd(prefixGcd[l], prefixGcd[r]);
        }

        return ret;
    }
};
