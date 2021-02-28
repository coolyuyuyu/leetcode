class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minNum = nums.front();
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            minNum = min(minNum, nums[i]);
            sum += nums[i];
        }
        
        return sum - minNum * nums.size();
    }
};