class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());

        for (size_t i = A.size(); 2 < i--;) {
            if (A[i] < A[i - 2] + A[i - 1]) {
                return A[i - 2] + A[i - 1] + A[i];
            }
        }

        return 0;
    }
};