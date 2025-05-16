class Solution {
public:
    vector<vector<int>> specialGrid(int n) {
        vector<vector<int>> ret(pow(2, n), vector<int>(pow(2, n)));
        stack<tuple<int, int, int, int>> stk({{0, 0, pow(2, n), 0}});
        while (!stk.empty()) {
            auto [r, c, len, val] = stk.top();
            stk.pop();

            if (len == 1) {
                ret[r][c] = val;
                continue;
            }

            len /= 2;
            int area = len * len;
            stk.emplace(r, c + len, len, val);
            stk.emplace(r + len, c + len, len, val + area * 1);
            stk.emplace(r + len, c, len, val + area * 2);
            stk.emplace(r, c, len, val + area * 3);
        }

        return ret;
    }
};
