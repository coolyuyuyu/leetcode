class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty())
            return 0;

        int ans = nums.front();
        int subAns = 0;
        for (vector<int>::const_iterator iter = nums.begin(); iter != nums.end(); ++iter) {
            subAns += *iter;
            ans = max(ans, subAns);
            subAns = max(subAns, 0);
        }
        return ans;
    }
};