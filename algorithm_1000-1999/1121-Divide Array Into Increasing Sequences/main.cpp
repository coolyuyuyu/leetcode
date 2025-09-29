class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int k) {
        int maxCnt = 0;
        for (int i = 0, n = nums.size(), preNum = INT_MIN, curCnt = 0; i < n; ++i) {
            curCnt = preNum < nums[i] ? 1 : (curCnt + 1);
            preNum = nums[i];
            maxCnt = std::max(maxCnt, curCnt);
        }

        return maxCnt * k <= nums.size();
    }
};
