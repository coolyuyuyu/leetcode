class Solution {
public:
    int rob(vector<int>& nums) {
        int cur = 0;
        int pre = 0;
        for (size_t index = 0; index < nums.size(); ++index) {
            int tmpCur = cur;
            cur = max(pre + nums[index], cur);
            pre = tmpCur;
        }
        return cur;
    }
};