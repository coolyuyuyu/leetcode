class Solution {
public:
    // O(m * n)
    int f1(const string& source, const string& target) {
        int ret = 0;
        for (int i = 0; i < target.size();) {
            int seqLen = 0;
            for (int j = 0; j < source.size() && (i + seqLen) < target.size(); ++j) {
                if (source[j] == target[i + seqLen]) {
                    ++seqLen;
                }
            }
            if (seqLen == 0) {
                return -1;
            }

            ++ret;
            i += seqLen;
        }

        return ret;
    }

    // Time: (m + n)
    int f2(string source, const string& target) {
        int m = source.size(), n = target.size();

        source.insert(source.begin(), '#');
        vector<vector<int>> next(m + 1, vector<int>(26));
        for (int j = 0; j < 26; ++j) {
            next[m][j] = -1;
        }
        for (int i = m; 0 < i--;) {
            for (int j = 0; j < 26; ++j) {
                next[i][j] = next[i + 1][j];
            }
            next[i][source[i + 1] - 'a'] = i + 1;
        }

        int ret = 1;
        for (int i = 0, index = 0; i < n;) {
            if (index == 0 && next[index][target[i] - 'a'] == -1) {
                return -1;
            }

            index = next[index][target[i] - 'a'];
            if (index == -1) {
                index = 0;
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
