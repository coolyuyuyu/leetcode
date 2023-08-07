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
    int v2(vector<int>& heights) {
        heights.push_back(0);
        heights.insert(heights.begin(), 0);

        int n = heights.size();

        stack<int> stk;

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                int h = heights[stk.top()];
                stk.pop();
                int area = h * (i - stk.top() - 1);
                ret = std::max(ret, area);
            }

            stk.push(i);
        }

        return ret;
    }

    int largestRectangleArea(vector<int>& heights) {
        //return v1(heights);
        return v2(heights);
    }
};
