class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> stk({0});

        int ret = 0;
        for (int num : nums) {
            while (!stk.empty() && stk.top() > num) {
                stk.pop();
            }

            if (stk.empty() || stk.top() < num) {
                ++ret;
                stk.push(num);
            }
        }

        return ret;
    }
};
