/**
 * Definition for an infinite stream.
 * class InfiniteStream {
 * public:
 *     InfiniteStream(vector<int> bits);
 *     int next();
 * };
 */
class Solution {
public:
    vector<int> computeLPS(vector<int>& pattern) {
        int n = pattern.size();

        // lps[i]: the maximal val k such that patter[0:k-1] == pattern[i-k+1:i]
        vector<int> lps(n);
        lps[0] = 0;
        for (int i = 1; i < n; ++i) {
            int j = lps[i - 1];
            while (0 < j && pattern[j] != pattern[i]) {
                j = lps[j - 1];
            }
            lps[i] = j + (pattern[j] == pattern[i] ? 1 : 0);
        }

        return lps;
    }

    int findPattern(InfiniteStream* stream, vector<int>& pattern) {
        int n = pattern.size();
        vector<int> lps = computeLPS(pattern);

        int j = (stream->next() == pattern[0] ? 1 : 0);
        if (j == n) {
            return 0;
        }

        int i = 1;
        for (; j < n; ++i) {
            int b = stream->next();
            while (0 < j && b != pattern[j]) {
                j = lps[j - 1];
            }
            j = j + (b == pattern[j] ? 1 : 0);
        }

        return i - n;
    }
};
