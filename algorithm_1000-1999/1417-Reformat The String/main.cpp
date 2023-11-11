class Solution {
public:
    string reformat(string s) {
        string digits, letters;
        for (char c : s) {
            if (isdigit(c)) {
                digits += c;
            }
            else {
                letters += c;
            }
        }
        int m = digits.size(), n = letters.size();

        if (abs(m - n) > 1) {
            return "";
        }

        string ret;
        if (m >= n) {
            for (int i = 0; i < n; ++i) {
                ret += digits[i];
                ret += letters[i];
            }
            if (m > n) {
                ret += digits[m - 1];
            }
        }
        else {
            for (int i = 0; i < m; ++i) {
                ret += letters[i];
                ret += digits[i];
            }
            ret += letters.back();
        }

        return ret;
    }
};
