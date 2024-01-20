class Solution {
public:
    int M = 1e9 + 7;

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        int preLE[n]; // prev less and equal
        int nxtLT[n]; // next less

        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && arr[stk.top()] > arr[i]) {
                nxtLT[stk.top()] = i;
                stk.pop();
            }
            preLE[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }
        for (; !stk.empty(); stk.pop()) {
            nxtLT[stk.top()] = n;
        }

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            int lftLen = i - preLE[i];
            int rhtLen = nxtLT[i] - i;
            ret += (1L * arr[i] * lftLen * rhtLen) % M;
            ret %= M;
        }

        return ret;
    }
};
