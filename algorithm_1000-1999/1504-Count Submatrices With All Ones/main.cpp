class Solution {
public:
    // Time: O(m * m * n)
    int bruteForce(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat.empty() ? 0 : mat[0].size();

        auto numOneRow = [&n](int h[]) -> int {
            int ret = 0;
            for (int i = 0, cnt = 0; i < n; ++i) {
                cnt = (h[i] ? cnt + 1 : 0);
                ret += cnt;
            }

            return ret;
        };

        int ret = 0;
        for (int top = 0; top < m; ++top) {
            int h[n];
            for (int col = 0; col < n; ++col) {
                h[col] = 1;
            }
            for (int btm = top; btm < m; ++btm) {
                for (int col = 0; col < n; ++col) {
                    h[col] &= mat[btm][col];
                }
                ret += numOneRow(h);
            }
        }

        return ret;
    }

    int monotonicStack(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat.empty() ? 0 : mat[0].size();

        int h[n + 1];
        for (int c = 0; c <= n; ++c) {
            h[c] = 0;
        }

        int ret = 0;
        for (int r = 0; r < m; ++r) {
            int cnt = 0;
            stack<int> stk({0});
            for (int c = 0; c < n; ++c) {
                h[c + 1] = (mat[r][c] == 1 ? h[c + 1] + 1 : 0);
                while (!stk.empty() && h[stk.top()] > h[c + 1]) {
                    int p1 = stk.top();
                    stk.pop();
                    int p2 = stk.top();

                    cnt -= (h[p1] - h[c + 1]) * (p1 - p2);
                }
                stk.push(c + 1);

                cnt += h[c + 1];
                ret += cnt;
            }
        }

        return ret;
    }

    int numSubmat(vector<vector<int>>& mat) {
        //return bruteForce(mat);
        return monotonicStack(mat);
    }
};
