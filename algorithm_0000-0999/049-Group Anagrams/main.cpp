class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size();

        // lps[i]: the longest length k such that word[0:k-1] == word[i-k+1:i]
        int lps[n];
        lps[0] = 0;
        for (int i = 1; i < n; ++i) {
            int j = lps[i - 1];
            while (j > 0 && word[j] != word[i]) {
                j = lps[j - 1];
            }
            lps[i] = j + (word[j] == word[i] ? 1 : 0);
        }

        int ret = 1;
        int j = lps[n - 1];
        while (j > 0 && (n - j) % k != 0) {
            j = lps[j - 1];
        }

        return j == 0 ? ((n + k - 1) / k) : ((n - j) / k);
    }
};
