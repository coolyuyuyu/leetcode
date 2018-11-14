class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        assert(!A.empty());

        size_t j = A.size() - 1;
        for (size_t i = 0; i < j; ++i) {
            if (A[i] % 2 == 1) {
                for (j; i < j; --j) {
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