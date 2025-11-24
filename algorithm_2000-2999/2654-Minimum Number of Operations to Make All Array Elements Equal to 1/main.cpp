class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int cnt1 = 0;
        int g = 0;
        for (int num : nums) {
            cnt1 += (num == 1);
            g = std::gcd(g, num);
        }
        if (cnt1 > 0) {
            return n - cnt1;
        }
        if (g > 1) {
            return -1;
        }

        int minLen = n;
        for (int i = 0; i < n; ++i) {
            int g = 0;
            for (int j = i; j < n; ++j) {
                g = std::gcd(g, nums[j]);
                if (g == 1) {
                    minLen = std::min(minLen, j - i + 1);
                    break;
                }
            }
        }

        return minLen + n - 2;
    }
};
