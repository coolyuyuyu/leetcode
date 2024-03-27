class Solution {
public:
    vector<int> find(const string& s, const string& t) {
        int m = s.size(), n = t.size();

        // lps[i]: the maximal value k such that t[0:k-1] == t[i-k+1:i]
        int lps[n];
        lps[0] = 0;
        for (int i = 1; i < n; ++i) {
            int j = lps[i - 1];
            while (0 < j && t[j] != t[i]) {
                j = lps[j - 1];
            }
            lps[i] = j + (t[j] == t[i] ? 1 : 0);
        }

        vector<int> ret;

        // dp[i]: the maximal value k such that s[i-k+1:i] == t[0:k-1]
        for (int i = 0, j = 0; i < m; ++i) {
            while (n <= j || (0 < j && s[i] != t[j])) {
                j = lps[j - 1];
            }
            j = j + (s[i] == t[j] ? 1 : 0);
            if (n <= j) {
                ret.push_back(i - n + 1);
            }
        }

        return ret;
    }

    string addBoldTag(string s, vector<string>& words) {
        int n = s.size();
        vector<int> diffs(n + 1, 0);
        for (const string& word : words) {
            vector<int> indexes = find(s, word);
            for (int index : indexes) {
                diffs[index] += 1;
                diffs[index + word.size()] -= 1;
            }
        }

        string ret;
        for (int i = 0, sum = 0; i <= n; ++i) {
            sum += diffs[i];
            if (sum > 0 && diffs[i] == sum) {
                ret += "<b>";
            }
            if (sum == 0 && diffs[i] < 0) {
                ret += "</b>";
            }

            if (i < n) {
                ret += s[i];
            }
        }

        return ret;
    }
};
