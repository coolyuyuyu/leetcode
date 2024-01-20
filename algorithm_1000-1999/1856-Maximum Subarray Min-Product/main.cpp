class Solution {
public:
    int M = 1e9 + 7;
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();

        int preLE[n]; // prev less and equal
        int nxtLT[n]; // next less

        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && nums[stk.top()] > nums[i]) {
                nxtLT[stk.top()] = i;
                stk.pop();
            }
            preLE[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }
        for (; !stk.empty(); stk.pop()) {
            nxtLT[stk.top()] = n;
        }

        long long presum[n];
        presum[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            presum[i] = presum[i - 1] + nums[i];
        }
        std::function<long long(int, int)> sum = [&](int lo, int hi) {
            return presum[hi] - (lo > 0 ? presum[lo - 1] : 0);
        };

        long long ret = 0;
        for (int i = 0; i < n; ++i) {
            int len = nxtLT[i] - preLE[i];
            ret = std::max(ret, 1LL * nums[i] * sum(preLE[i] + 1, nxtLT[i] - 1));
        }

        return (ret % M + M) % M;
    }
};
