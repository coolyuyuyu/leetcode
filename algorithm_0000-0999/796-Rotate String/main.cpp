class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.size() != B.size()) {
            return false;
        }
        if (A.empty() || A == B) {
            return true;
        }

        for (size_t round = 1; round < A.size(); ++round) {
            char c = A.front();
            for (size_t i = 1; i < A.size(); ++i) {
                A[i - 1] = A[i];
            }
            A.back() = c;


            if (A == B) {
                return true;
            }
        }

        return false;
    }
};