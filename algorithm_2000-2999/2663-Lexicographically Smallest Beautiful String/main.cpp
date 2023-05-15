class Solution {
public:
    bool checkOk(const string& s, size_t i, char c) {
        if (0 < i && s[i - 1] == c) {
            return false;
        }
        if (1 < i && s[i - 2] == c) {
            return false;
        }
        return true;
    }

    string smallestBeautifulString(string s, int k) {
        size_t i;
        bool flag = false;
        for (i = s.size(); !flag && 0 < i--;) {
            for (char c = s[i] + 1; c < ('a' + k); ++c) {
                if (checkOk(s, i, c)) {
                    s[i] = c;
                    flag = true;
                    break;
                }
            }
        }
        if (!flag) {
            return "";
        }

        for (i = i + 1; i < s.size(); ++i) {
            for (char c = 'a'; c < ('a' + k); ++c) {
                if (checkOk(s, i, c)) {
                    s[i] = c;
                    break;
                }
            }
        }

        return s;
    }
};
