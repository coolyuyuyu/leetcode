class Solution {
public:
    // Time: O(3N)
    int f1(vector<int>& heights) {
        int n = heights.size();
        stack<int> stk;

        int nxtLT[n];
        std::fill(nxtLT, nxtLT + n, n);
        while (!stk.empty()) { stk.pop(); }
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                nxtLT[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        int preLT[n];
        std::fill(preLT, preLT + n, -1);
        while (!stk.empty()) { stk.pop(); }
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                preLT[i] = stk.top();
            }
            stk.push(i);
        }

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            ret = std::max(ret, (nxtLT[i] - preLT[i] - 1) * heights[i]);
        }

        return ret;
    }

    // Time: O(N)
    int f2(vector<int>& heights) {
        heights.push_back(0);
        heights.insert(heights.begin(), 0);
        stack<int> stk;

        int ret = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                int h = heights[stk.top()];
                stk.pop();
                ret = std::max(ret, (i - stk.top() - 1) * h);
            }
            stk.push(i);
        }

        return ret;
    }

    int largestRectangleArea(vector<int>& heights) {
        //return f1(heights);
        return f2(heights);
    }
};
