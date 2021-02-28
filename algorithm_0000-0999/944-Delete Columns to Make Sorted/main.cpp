class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int ans = 0;

        size_t n = A.size();
        size_t k = A.front().size();
        for (size_t i = 0; i < k; ++i) {
            bool nondecreasing = true;
            for (size_t j = 1; j < n && nondecreasing; ++j) {
                if (A[j][i] < A[j - 1][i]) {
                    nondecreasing = false;
                }
            }

            if (!nondecreasing) {
                ++ans;
            }
        }

        return ans;
    }
};