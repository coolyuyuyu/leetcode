class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();

        string ret(n + m - 1, '?');
        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'F') { continue; }
            for (int j = 0; j < m; ++j) {
                if (ret[i + j] == '?') {
                    ret[i + j] = str2[j];
                }
                else if (ret[i + j] != str2[j]) {
                    return "";
                }
            }
        }

        vector<bool> fixed(ret.size(), true);
        for (int i = 0; i < ret.size(); ++i) {
            if (ret[i] != '?') { continue; }
            ret[i] = 'a';
            fixed[i] = false;
        }

        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'T') { continue; }

            bool different = false;
            int idx = -1;
            for (int j = m; 0 < j--;) {
                if (ret[i + j] != str2[j]) {
                    different = true;
                }
                else if (!fixed[i + j] && idx == -1) {
                    idx = i + j;
                }
            }

            if (different) {
                ;
            }
            else if (idx != -1) {
                ret[idx] = 'b';
            }
            else {
                return "";
            }
        }

        return ret;
    }
};
