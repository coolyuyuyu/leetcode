class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long sum = 0, M = 1e9 + 7;
        for (int num : nums) {
            sum += num;
        }
        long long x = (sum - k + k - 1) / k % M;
        return (1 + x) * x / 2 % M;
    }
};
