class Solution {
public:
    // Time: O(n)
    int maxWidthRamp(vector<int>& nums) {
        // monotonic stack
        // farthest greater or equal element

        int n = nums.size();

        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            if (stk.empty() || nums[stk.top()] > nums[i]) {
                stk.push(i);
            }
        }

        int ret = 0;
        for (int j = n; 0 < j--;) {
            while (!stk.empty() && nums[stk.top()] <= nums[j]) {
                int i = stk.top();
                stk.pop();
                ret = std::max(ret,  j - i);
            }
        }

        return ret;
    }
};
