class Solution {
public:
    // Time: O(n)
    int maxSubarrayLength(vector<int>& nums) {
        // monotonic stack
        // farthest smaller element

        stack<int> stk;
        for (int i = 0; i < nums.size(); ++i) {
            if (stk.empty() || nums[stk.top()] < nums[i]) {
                stk.push(i);
            }
        }

        int ret = 0;
        for (int j = nums.size(); 0 < j--;) {
            while (!stk.empty() && nums[stk.top()] > nums[j]) {
                ret = std::max(ret, j - stk.top() + 1);
                stk.pop();
            }
        }

        return ret;
    }
};
