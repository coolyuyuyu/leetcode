class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        size_t j = 1;
        for (size_t i = 0; i < A.size(); i += 2) {
            if (A[i] % 2 == 1) {
                for (; j < A.size(); j += 2) {
                    if (A[j] % 2 == 0) {
                        break;
                    }
                }

                swap(A[i], A[j]);
            }
        }

        return A;
    }
};