class Solution {
public:
    // Time: O((m + n) * k), k is the size of dictionary
    string byTwoPointers(string s, vector<string>& dictionary) {
        int m = s.size();
        std::function<bool(const string&)> checkOk = [&](const string& word) {
            int n = word.size();
            int i = 0, j = 0;
            while (i < m && j < n) {
                if (s[i] == word[j]) {
                    ++j;
                }
                ++i;
            }

            return j >= n;
        };

        string ret;
        for (const string& word : dictionary) {
            if (checkOk(word)) {
                if (word.size() > ret.size() || (word.size() == ret.size() && word < ret)) {
                    ret = word;
                }
            }
        }

        return ret;
    }

    // Time: O(m +  n * k), k is the size of dictionary
    string byStateMachine(string s, vector<string>& dictionary) {
        int m = s.size();
        s = "#" + s;

        // next[i][ch]: the position of ch to the right of i
        int next[m + 1][26];
        std::fill(next[m], next[m] + 26, -1);
        for (int i = m; 0 < i--;) {
            std::copy(next[i + 1], next[i + 1] + 26, next[i]);
            next[i][s[i + 1] - 'a'] = i + 1;
        }

        std::function<bool(const string&)> checkOk = [&](const string& word) {
            int i = 0;
            for (char c : word) {
                i = next[i][c - 'a'];
                if (i == -1) {
                    return false;
                }
            }

            return true;
        };

        string ret;
        for (const string& word : dictionary) {
            if (checkOk(word)) {
                if (word.size() > ret.size() || (word.size() == ret.size() && word < ret)) {
                    ret = word;
                }
            }
        }

        return ret;
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        //return byTwoPointers(s, dictionary);
        return byStateMachine(s, dictionary);
    }
};
