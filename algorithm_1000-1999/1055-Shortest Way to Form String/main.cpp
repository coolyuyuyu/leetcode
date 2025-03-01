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
        int m = source.size(), n = target.size();

        source = "#" + source;
        int next[m + 1][26];
        for (char c = 'a'; c <= 'z'; ++c) {
            next[m][c - 'a'] = -1;
        }
        for (int j = m - 1; j >= 0; j--) {
            for (char c = 'a'; c <= 'z'; ++c) {
                next[j][c - 'a'] = next[j + 1][c - 'a'];
            }
            next[j][source[j + 1] - 'a'] = j + 1;
        }


        int ret = 1;
        for (int i = 0, j = 0; i < n;) {
            if (j == 0 && next[j][target[i] - 'a'] == -1) {
                return -1;
            }

            j = next[j][target[i] - 'a'];
            if (j == -1) {
                j = 0;
                ++ret;
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
