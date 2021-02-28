class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size() < 3) {
            return false;
        }

        size_t i = 0;
        for (; i < A.size(); ++i) {
            if (i + 1 >= A.size() || A[i] >= A[i + 1]) {
                break;
            }
        }

        if (i == 0 || i + 1 == A.size()) {
            return false;
        }

        for (; i < A.size(); ++i) {
            if (i + 1 >= A.size() || A[i] <= A[i + 1]) {
                break;
            }
        }

        return (i + 1 == A.size());
    }
};