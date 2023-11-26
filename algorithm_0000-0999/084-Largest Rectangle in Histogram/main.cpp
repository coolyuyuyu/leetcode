class Solution {
public:
    // Time: O(3n)
    int v1(const vector<int>& heights) {
        int n = heights.size();

        stack<int> stk;

        vector<int> preSmaller(n, -1);
        while (!stk.empty()) {
            stk.pop();
        }
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                preSmaller[i] = stk.top();
            }

            stk.push(i);
        }

        vector<int> nxtSmaller(n, n);
        while (!stk.empty()) {
            stk.pop();
        }
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                nxtSmaller[stk.top()] = i;
                stk.pop();
            }

            stk.push(i);
        }

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            int area = heights[i] * (nxtSmaller[i] - preSmaller[i] - 1);
            ret = std::max(ret, area);
        }

        return ret;
    }

    // Time: O(n)
    int monotonicStack(vector<int>& heights) {
        heights.push_back(0);
        
        int n = heights.size();

        stack<int> stk;

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                int h = heights[stk.top()];
                stk.pop();

                int rht = i - 1;
                int lft = stk.empty() ? 0 : (stk.top() + 1);
                ret = std::max(ret, h * (rht - lft + 1));
            }

            stk.push(i);
        }

        return ret;
    }

    int largestRectangleArea(vector<int>& heights) {
        //return v1(heights);
        return monotonicStack(heights);
    }
};
