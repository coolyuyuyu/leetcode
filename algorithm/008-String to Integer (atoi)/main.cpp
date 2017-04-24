class Solution {
public:
    int myAtoi(string str) {
        string::iterator it = str.begin();
        while (it != str.end() && *it == ' ') {
            ++it;
        }

        int indicator = 1;
        if (it != str.end()) {
            if (*it == '+') {
                ++it;
            }
            else if (*it == '-') {
                indicator = -1;
                ++it;
            }
        }

        long num = 0;
        while (it != str.end()) {
            if (!isdigit(*it)) {
                break;
            }
            num = num * 10 + (*it - '0');
            if (num * indicator >= INT_MAX) {
                return INT_MAX;
            }
            else if (num * indicator <= INT_MIN) {
                return INT_MIN;
            }
            ++it;
        }

        num *= indicator;
        return num;
    }
};