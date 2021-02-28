class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        enum Type {INC, DESC, EQL};

        Type a = EQL;
        for (size_t i = 0; i + 1 < A.size(); ++i) {
            Type b;
            if (A[i] < A[i + 1]) {
                b = INC;
            }
            else if (A[i] == A[i + 1]) {
                b = EQL;
            }
            else {
                b = DESC;
            }

            if (a == EQL) {
                a = b;
            }
            else {
                if (b != EQL && b != a) {
                    return false;
                }
            }
        }

        return true;
    }
};