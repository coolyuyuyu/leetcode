class Solution {
public:
    // Time: O(m * m * n)
    int bruteForce(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat.empty() ? 0 : mat[0].size();

        auto countContinuousOne = [&n](int h[n]) {
            int ret = 0;
            for (int c = 0, cnt = 0; c < n; ++c) {
                cnt = h[c] == 1 ? (cnt + 1) : 0;
                ret += cnt;
            }
            return ret;
        };

        int ret = 0;
        for (int top = 0; top < m; ++top) {
            int h[n];
            for (int c = 0; c < n; ++c) {
                h[c] = 1;
            }
            for (int btm = top; btm < m; ++btm) {
                for (int c = 0; c < n; ++c) {
                    h[c] &= mat[btm][c];
                }
                ret += countContinuousOne(h);
            }
        }

        return ret;
    }

    // Time: O(m * n)
    int monotonicStack(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat.empty() ? 0 : mat[0].size();

        int h[n];
        for (int c = 0; c < n; ++c) {
            h[c] = 0;
        }

        int ret = 0;
        for (int r = 0; r < m; ++r) {
            int cnt = 0;
            stack<int> stk({-1});
            for (int c = 0; c < n; ++c) {
                h[c] = mat[r][c] == 1 ? (h[c] + 1) : 0;

                while (!stk.empty() && (stk.top() >= 0 ? h[stk.top()] : 0) > h[c]) {
                    int p1 = stk.top();
                    stk.pop();
                    int p2 = stk.top();
                    cnt -= (h[p1] - h[c]) * (p1 - p2);
                }
                stk.push(c);

                cnt += h[c];
                ret += cnt;
            }
        }

        return ret;
    }

    int numSubmat(vector<vector<int>>& mat) {
        return bruteForce(mat);
        //return monotonicStack(mat);
    }
};
