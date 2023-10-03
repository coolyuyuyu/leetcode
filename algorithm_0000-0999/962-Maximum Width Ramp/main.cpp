class Solution {
public:
    // Time: O(n)
    int maxWidthRamp(vector<int>& nums) {
        // monotonic stack
        // farthest greater or equal element

        stack<int> stk;
        for (int i = 0; i < nums.size(); ++i) {
            if (stk.empty() || nums[stk.top()] > nums[i]) {
                stk.push(i);
            }
        }

        int ret = 0;
        for (int j = nums.size(); 0 < j--;) {
            while (!stk.empty() && nums[j] >= nums[stk.top()]) {
                ret = std::max(ret, j - stk.top());
                stk.pop();
            }
        }

        return ret;
    }
};
