class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        // 84. Largest Rectangle in Histogram

        nums.insert(nums.begin(), 0);
        nums.push_back(0);

        int n = nums.size();

        stack<int> stk;

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && nums[stk.top()] > nums[i]) {
                int h = nums[stk.top()];
                stk.pop();
                int w = i - stk.top() - 1;

                if (threshold < w * h) {
                    return w;
                }
            }
            stk.push(i);
        }

        return -1;
    }
};
