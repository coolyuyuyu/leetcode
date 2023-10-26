class Solution {
public:
    int secondHighest(string s) {
        char a = '0' - 1, b = '0' - 2;
        for (char c : s) {
            if (!isdigit(c)) { continue; }

            if (a < c) {
                b = a;
                a = c;
            }
            else if (a == c) {
            }
            else if (b < c) {
                b = c;
            }
        }

        if (b >= '0') {
            return b - '0';
        }
        else {
            return -1;
        }
    }
};
