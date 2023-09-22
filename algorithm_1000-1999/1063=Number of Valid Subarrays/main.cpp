class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        nums.push_back(INT_MIN);

        stack<int> stk;
        int ret = 0;
        for (int i = 0; i < nums.size(); ++i) {
            while (!stk.empty() && nums[stk.top()] > nums[i]) {
                ret += i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }

        return ret;
    }
};