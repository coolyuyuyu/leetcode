class Solution {
public:
    vector<vector<int>> seePeople(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights.empty() ? 0 : heights[0].size();

        vector<vector<int>> ret(m, vector<int>(n, 0));
        for (int r = 0; r < m; ++r) {
            stack<int> stk; // monotonic
            for (int c = 0; c < n; ++c) {
                int lastRemoved = 0;
                while (!stk.empty() && heights[r][stk.top()] <= heights[r][c]) {
                    ++ret[r][stk.top()];
                    lastRemoved = heights[r][stk.top()];
                    stk.pop();
                }
                if (!stk.empty() && lastRemoved != heights[r][c]) {
                    ++ret[r][stk.top()];
                }

                stk.push(c);
            }
        }

        for (int c = 0; c < n; ++c) {
            stack<int> stk; // monotonic
            for (int r = 0; r < m; ++r) {
                int lastRemoved = 0;
                while (!stk.empty() && heights[stk.top()][c] <= heights[r][c]) {
                    ++ret[stk.top()][c];
                    lastRemoved = heights[stk.top()][c];
                    stk.pop();
                }
                if (!stk.empty() && lastRemoved != heights[r][c]) {
                    ++ret[stk.top()][c];
                }

                stk.push(r);
            }
        }

        return ret;
    }
};
