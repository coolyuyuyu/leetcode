class Solution {
public:
    vector<int> maximumLengthOfRanges(vector<int>& nums) {
        int n = nums.size();

        stack<int> stk;

        int nxtGT[n];
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            while (!stk.empty() && nums[stk.top()] < nums[i]) {
                nxtGT[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        for (; !stk.empty(); stk.pop()) {
            nxtGT[stk.top()] = n;
        }

        int preGT[n];
        for (int i = n; 0 < i--;) {
            int num = nums[i];
            while (!stk.empty() && nums[stk.top()] < nums[i]) {
                preGT[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        for (; !stk.empty(); stk.pop()) {
            preGT[stk.top()] = -1;
        }

        vector<int> ret(n);
        for (int i = 0; i < n; ++i) {
            ret[i] = (i - preGT[i] - 1) + (nxtGT[i] - i - 1) + 1;
        }
        return ret;
    }
};
