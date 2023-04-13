class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ret(n, 0);

        stack<int> stk; // monotonic
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && heights[stk.top()] < heights[i]) {
                ++ret[stk.top()];
                stk.pop();
            }
            if (!stk.empty()) {
                ++ret[stk.top()];
            }

            stk.push(i);
        }

        return ret;
    }
};
