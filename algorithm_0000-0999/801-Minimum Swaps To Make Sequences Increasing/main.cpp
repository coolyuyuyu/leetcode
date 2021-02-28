class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int curNonSwap = 0;
        int curSwap = 1;
        for (size_t i = 1; i < A.size(); ++i) {
            int preNonSwap = curNonSwap;
            int preSwap = curSwap;
            curNonSwap = numeric_limits<int>::max();
            curSwap = numeric_limits<int>::max();

            // cur no swap, pre no swap || cur swap, pre swap
            if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
                curNonSwap = min(curNonSwap, preNonSwap);
                curSwap = min(curSwap, preSwap + 1);
            }

            // cur no swap, pre swap || cur swap, pre no swap
            if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
                curNonSwap = min(curNonSwap, preSwap);
                curSwap = min(curSwap, preNonSwap + 1);
            }
        }

       return min(curNonSwap, curSwap);
    }
};