// 84. Largest Rectangle in Histogram

class Solution {
public:
    // Time: O(3N)
    int f1(vector<int>& nums, int threshold) {
        int n = nums.size();
        stack<int> stk;

        int nxtLT[n];
        std::fill(nxtLT, nxtLT + n, n);
        while (!stk.empty()) { stk.pop(); }
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && nums[stk.top()] > nums[i]) {
                nxtLT[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        int preLT[n];
        std::fill(preLT, preLT + n, -1);
        while (!stk.empty()) { stk.pop(); }
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && nums[stk.top()] > nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                preLT[i] = stk.top();
            }
            stk.push(i);
        }

        for (int i = 0; i < n; ++i) {
            int w = nxtLT[i] - preLT[i] - 1;
            int h = nums[i];
            if (h > threshold / w) {
                return w;
            }
        }

        return -1;
    }

    // Time: O(N)
    int f2(vector<int>& nums, int threshold) {
        nums.push_back(0);
        nums.insert(nums.begin(), 0);
        stack<int> stk;

        for (int i = 0; i < nums.size(); ++i) {
            while (!stk.empty() && nums[stk.top()] > nums[i]) {
                int h = nums[stk.top()];
                stk.pop();
                int w = i - stk.top() - 1;
                if (h > threshold / w) {
                    return w;
                }
            }
            stk.push(i);
        }

        return -1;
    }

    int validSubarraySize(vector<int>& nums, int threshold) {
        //return f1(nums, threshold);
        return f2(nums, threshold);
    }
};
