class Solution {
public:
    int numTrees(int n) {
        vector<int> nums = {1};
        for (int i = 1; i <= n; ++i) {
            int num = 0;
            for (int j = 0; j < i; ++j) {
                num += (nums[j] * nums[i - j - 1]);
            }
            nums.push_back(num);
        }
        
        return nums[n];
    }
};
