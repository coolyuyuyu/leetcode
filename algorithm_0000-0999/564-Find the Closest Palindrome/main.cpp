class Solution {
public:
    string nearestPalindromic(string n) {
        std::function<string(const string&)> nextSmallerPalindrom = [](const string& s) {
            int n = s.size();
            string t = s;

            for (int i = (n - 1) / 2; 0 <= i; --i) {
                t[n - 1 - i] = t[i];
            }
            if (t < s) {
                return t;
            }

            int carry = -1;
            for (int i = (n - 1) / 2; 0 <= i; --i) {
                t[i] += carry;
                if (isdigit(t[i])) {
                    carry = 0;
                }
                else {
                    t[i] = '9';
                }
                t[n - 1 - i] = t[i];
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
            string t = s;

            for (int i = (n - 1) / 2; 0 <= i; --i) {
                t[n - 1 - i] = t[i];
            }
            if (t > s) {
                return t;
            }

            int carry = 1;
            for (int i = (n - 1) / 2; 0 <= i; --i) {
                t[i] += carry;
                if (isdigit(t[i])) {
                    carry = 0;
                }
                else {
                    t[i] = '0';
                }
                t[n - 1 - i] = t[i];
            }

            if (carry) {
                t.assign(n + 1, '0');
                t[0] = t[n] = '1';
                return t;
            }
            else {
                return t;
            }
        };

        string a = nextSmallerPalindrom(n);
        string b = nextGreaterPalindrom(n);
        if (stoll(n) - stoll(a) <= stoll(b) - stoll(n)) {
            return a;
        }
        else {
            return b;
        }
    }
};
