class Solution {
public:
    int dp(const vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();
        int dpL[n]; // dpL[r][c]: the lft bound of the maximal rect covering point (r,c)
        std::fill(dpL, dpL + n, 0);
        int dpR[n]; // dpR[r][c]: the rht bound of the maximal rect covering point (r,c)
        std::fill(dpR, dpR + n, n);
        int dpH[n]; // dpH[r][c]: the height bound of the maximal rect covering point (r,c)
        std::fill(dpH, dpH + n, 0);

        int ret = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0, lftMost = 0; c < n; ++c) {
                if (matrix[r][c] == '1') {
                    dpL[c] = std::max(dpL[c], lftMost);
                }
                else {
                    lftMost = c + 1;
                    dpL[c] = 0;
                }
            }
            for (int c = n - 1, rhtMost = n; c >= 0; --c) {
                if (matrix[r][c] == '1') {
                    dpR[c] = std::min(dpR[c], rhtMost);
                }
                else {
                    rhtMost = c;
                    dpR[c] = n;
                }
            }
            for (int c = 0; c < n; ++c) {
                if (matrix[r][c] == '1') {
                    dpH[c] = dpH[c] + 1;
                }
                else {
                    dpH[c] = 0;
                }
            }

            for (int c = 0; c < n; ++c) {
                ret = std::max(ret, (dpR[c] - dpL[c]) * dpH[c]);
            }
        }

        return ret;
    }

    int monotonic_stack(const vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();

        // 84. Largest Rectangle in Histogram
        std::function<int(vector<int>)> largestRectangleArea = [](vector<int> heights) {
            heights.insert(heights.begin(), 0);
            heights.push_back(0);

            int n = heights.size();

            stack<int> stk;

            int ret = 0;
            for (int i = 0; i < n; ++i) {
                while (!stk.empty() && heights[stk.top()] > heights[i]) {
                    int h = heights[stk.top()];
                    stk.pop();
                    int w = i - stk.top() - 1;

                    ret = std::max(ret, w * h);
                }
                stk.push(i);
            }

            return ret;
        };

        vector<int> hist(n, 0);

        int ret = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (matrix[r][c] == '1') {
                    hist[c] += 1;
                }
                else {
                    hist[c] = 0;
                }
            }
            ret = std::max(ret, largestRectangleArea(hist));
        }

        return ret;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        //return dp(matrix);
        return monotonic_stack(matrix);
    }
};
