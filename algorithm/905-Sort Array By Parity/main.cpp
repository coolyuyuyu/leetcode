class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        assert(!A.empty());

        for (size_t i = 0, j = A.size() - 1; i < j; ++i) {
            if (A[i] % 2 == 1) {
                for (; i < j; --j) {
                    if (A[j] % 2 == 0) {
                        swap(A[i], A[j--]);
                        break;
                    }
                }
            }
        }

        return A;
    }
};