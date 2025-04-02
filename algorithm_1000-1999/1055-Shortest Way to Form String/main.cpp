class Solution {
public:
    // O(m * n)
    int f1(const string& source, const string& target) {
        int ret = 0;
        for (int i = 0, m = target.size(), n = source.size(), len = 0; i < m; i += len, ++ret, len = 0) {
            for (int j = 0; j < n && i + len < m; ++j) {
                if (source[j] == target[i + len]) {
                    ++len;
                }
            }
            if (len == 0) {
                return -1;
            }
        }

        return ret;
    }

    // Time: (m + n)
    int f2(string source, const string& target) {
        int n = source.size(), m = target.size();

        source = "#" + source;

        int next[n + 1][26];
        for (int c = 0; c < 26; ++c) {
            next[n][c] = -1;
        }
        for (int j = n - 1; j >= 0; --j) {
            for (int c = 0; c < 26; ++c) {
                next[j][c] = next[j + 1][c];
            }
            next[j][source[j + 1] - 'a'] = j + 1;
        }

        int ret = 1;
        for (int i = 0, j = 0; i < m;) {
            if (j == 0 && next[j][target[i] - 'a'] == -1) {
                return -1;
            }

            j = next[j][target[i] - 'a'];
            if (j == -1) {
                ++ret;
                j = 0;
            }
            else {
                ++i;
            }
        }

        return ret;
    }

    int shortestWay(string source, string target) {
        //return f1(source, target);
        return f2(source, target);
    }
};
