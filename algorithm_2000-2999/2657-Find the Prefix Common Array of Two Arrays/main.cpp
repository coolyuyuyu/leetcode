class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int> cnts(n + 1, 0);

        vector<int> ret(n, 0);
        for (int i = 0, sum = 0; i < n; ++i) {
            if (++cnts[A[i]] == 2) {
                ++sum;
            }
            if (++cnts[B[i]] == 2) {
                ++sum;
            }
            ret[i] = sum;
        }

        return ret;
    }
};
