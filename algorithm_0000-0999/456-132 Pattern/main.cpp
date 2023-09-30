class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();

        vector<int> lftMin(n);
        lftMin[0] = INT_MAX;
        for (int i = 1; i < n; ++i) {
            lftMin[i] = std::min(lftMin[i - 1], nums[i - 1]);
        }

        // next smaller
        stack<int> stk;
        for (int i = nums.size(); 0 < i--;) {
            int second = INT_MIN;
            while (!stk.empty() && nums[i] > stk.top()) {
                second = stk.top();
                stk.pop();
            }

            if (lftMin[i] < second) {
                return true;
            }

            stk.push(nums[i]);
        }

        return false;
    }
};
