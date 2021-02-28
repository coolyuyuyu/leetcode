class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        assert(2 <= A.size());

        for (size_t i = 0, j = 1; i < A.size() && j < A.size(); i += 2) {
            if (A[i] % 2 == 1) {
                for (; j < A.size(); j += 2) {
                    if (A[j] % 2 == 0) {
                        swap(A[i], A[j]);
                        j += 2;
                        break;
                    }
                }
            }
        }

        return A;
    }
};