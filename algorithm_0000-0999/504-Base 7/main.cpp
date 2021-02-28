class Solution {
public:
    string convertToBase7(int num) {
        bool positive;
        if (num >= 0) {
            positive = true;
        }
        else {
            positive = false;
            num = -num;
        }

        string result;
        do {
            result.push_back(num % 7 + '0');
            num /= 7;
        } while (num);
        reverse(result.begin(), result.end());

        if (!positive) {
            result.insert(result.begin(), '-');
        }

        return result;
    }
};