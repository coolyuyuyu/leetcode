class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        vector<int> indexes(100001);
        for (size_t i = 0; i < B.size(); ++i) {
            indexes[B[i]] = i;
        }

        vector<int> results(A.size());
        for (size_t i = 0; i < A.size(); ++i) {
            results[i] = indexes[A[i]];
        }

        return results;
    }
};