class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int x = numsDivide[0];
        for (int i = 1; i < numsDivide.size(); ++i) {
            x = std::gcd(x, numsDivide[i]);
        }

        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if ((x % nums[i]) == 0) {
                return i;
            }
        }
        return -1;
    }
};
