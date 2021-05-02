class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {;
        vector<bool> results(A.size());

        int num = 0;
        for (size_t i = 0; i < A.size(); ++i) {
            num *= 2;
            num += A[i];

            num %= 5;

            results[i] = (num == 0);
        }

        return results;
    }
};
