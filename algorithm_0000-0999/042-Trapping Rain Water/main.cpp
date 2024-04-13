class Solution {
public:
    // three-pass
    // Time: O(N)
    int f1(vector<int>& height) {
        int n = height.size();

        // lftMax[i]: the max height of height[0:i]
        int lftMax[n];
        lftMax[0] = height[0];
        for (int i = 1; i < n; ++i) {
            lftMax[i] = std::max(lftMax[i - 1], height[i]);
        }

        // rhtMax[i]: the max height of height[i:n-1]
        int rhtMax[n];
        rhtMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rhtMax[i] = std::max(rhtMax[i + 1], height[i]);
        }

        int ret = 0;
        for (int i = 1; i + 1 < n; ++i) {
            ret += std::max(std::min(lftMax[i - 1], rhtMax[i + 1]) - height[i], 0);
        }

        return ret;
    }

    // monotonic stack
    // Time: O(N)
    int f2(vector<int>& height) {
        int ret = 0;
        stack<int> stk;
        for (int i = 0; i < height.size(); ++i) {
            while (!stk.empty() && height[stk.top()] < height[i]) {
                int base = height[stk.top()];
                stk.pop();

                if (stk.empty()) {
                    break;
                }

                int w = i - stk.top() - 1;
                int h = std::min(height[stk.top()], height[i]) - base;
                ret += w * h;
            }
            stk.push(i);
        }

        return ret;
    }

    int trap(vector<int>& height) {
        //return f1(height);
        return f2(height);
    }
};
