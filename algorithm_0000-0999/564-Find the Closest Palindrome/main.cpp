class Solution {
public:
    string nearestPalindromic(string n) {
        std::function<string(const string&)> nextSmallerPalindrom = [](const string& s) {
            int n = s.size();
            string t(s);

            for (int l = 0, r = n - 1; l < r; ++l, --r) {
                t[r] = t[l];
            }
            if (t < s) {
                return t;
            }

            int carry = -1;
            for (int i = (n - 1) / 2; i >= 0; --i) {
                t[i] += carry;
                if (isdigit(t[i])) {
                    carry = 0;
                }
                else {
                    t[i] = '9';
                    carry = -1;
                }
                t[n - i - 1] = t[i];
            }
            if (t[0] == '0' && n > 1) {
                return string(n - 1, '9');
            }
            else {
                return t;
            }
        };
        std::function<string(const string&)> nextGreaterPalindrom = [](const string& s) {
            int n = s.size();
            string t(s);

            for (int l = 0, r = n - 1; l < r; ++l, --r) {
                t[r] = t[l];
            }
            if (t > s) {
                return t;
            }

            int carry = 1;
            for (int i = (n - 1) / 2; i >= 0; --i) {
                t[i] += carry;
                if (isdigit(t[i])) {
                    carry = 0;
                }
                else {
                    t[i] = '0';
                    carry = 1;
                }
                t[n - 1 - i] = t[i];
            }
            if (carry) {
                t.assign(n + 1, '0');
                t[0] = t[n] = '1';
            }

            return t;
        };

        string nxt = nextGreaterPalindrom(n);
        string pre = nextSmallerPalindrom(n);
        if (stoll(n) - stoll(pre) <= stoll(nxt) - stoll(n)) {
            return pre;
        }
        else {
            return nxt;
        }
    }
};
