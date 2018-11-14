class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        assert(!A.empty());

        int maxNum = A.front();
        int minNum = A.front();
        for (size_t i = 1; i < A.size(); ++i) {
            if (A[i] < minNum) {
                minNum = A[i];
            }
            else if (A[i] > maxNum) {
                maxNum = A[i];
            }
        }

        int diff = maxNum - minNum - 2 * K;
        if (diff < 0) {
            diff = 0;
        }
        return diff;
    }
};