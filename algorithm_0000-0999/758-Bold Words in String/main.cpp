class Solution {
public:
    string boldWords(vector<string>& words, string s) {
        int n = s.size();
        int diffs[n + 1];
        std::fill(diffs, diffs + n + 1, 0);

        std::function<vector<int>(const string&, const string&)> find = [](const string& haystack, const string& needle) {
            int m = haystack.size(), n = needle.size();

            // lps[i]: the maximum value k such that needle[0:k-1] == needle[i-k+1:i]
            int lps[n];
            lps[0] = 0;
            for (int i = 1; i < n; ++i) {
                int j = lps[i - 1];
                while (0 < j && needle[j] != needle[i]) {
                    j = lps[j - 1];
                }
                lps[i] = j + (needle[j] == needle[i] ? 1 : 0);
            }

            vector<int> ret;
            for (int i = 0, j = 0; i < m; ++i) {
                while (j == n || (0 < j && haystack[i] != needle[j])) {
                    j = lps[j - 1];
                }
                j = j + (haystack[i] == needle[j] ? 1 : 0);

                if (j == n) {
                    ret.push_back(i - n + 1);
                }
            }

            return ret;
        };

        for (const string& word : words) {
            vector<int> indexes = find(s, word);
            for (int index : indexes) {
                diffs[index] += 1;
                diffs[index + word.size()] -= 1;
            }
        }

        string ret;
        for (int i = 0, sum = 0; i < n + 1; ++i) {
            if (sum == 0 && sum + diffs[i] > 0) {
                ret += "<b>";
            }
            else if (sum > 0 && sum + diffs[i] == 0) {
                ret += "</b>";
            }

            if (i < n) {
                ret += s[i];
            }

            sum += diffs[i];
        }

        return ret;
    }
};
