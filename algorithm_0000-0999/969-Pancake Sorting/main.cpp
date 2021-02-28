class Solution {
public:

    vector<int> pancakeSort(vector<int>& A) {
        vector<int> ans;

        size_t n = A.size();
        for (size_t i = n; 0 < i--;) {
            if (A[i] == i + 1) {
                continue;
            }

            int index = find(A.begin(), A.begin() + i, i + 1) - A.begin();
            if (0 < index) {
                ans.emplace_back(index + 1);
                reverse(A.begin(), A.begin() + index + 1);
            }

            ans.emplace_back(i + 1);
            reverse(A.begin(), A.begin() + i + 1);
        }

        return ans;
    }
};