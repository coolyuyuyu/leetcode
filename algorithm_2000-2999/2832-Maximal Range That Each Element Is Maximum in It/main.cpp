class Solution {
public:
    vector<int> maximumLengthOfRanges(vector<int>& nums) {
        int n = nums.size();
        stack<int> stk;

        int nxtGT[n];
        for (int i = 0; i < n; ++i) {
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
            while (!stk.empty() && nums[i] > nums[stk.top()] ) {
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
            ret[i] = nxtGT[i] - preGT[i] - 1;
        }

        return ret;
    }
};
