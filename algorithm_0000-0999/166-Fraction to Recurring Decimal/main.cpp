class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) { return "0"; }

        long a = numerator, b = denominator;
        int sign = 1;
        if (a < 0) {
            a *= -1;
            sign *= -1;
        }
        if (b < 0) {
            b *= -1;
            sign *= -1;
        }

        string ret;
        if (sign < 0) {
            ret.push_back('-');
        }
        ret += std::to_string(a / b);

        long rem = a % b;
        if (rem == 0) { return ret; }
        ret.push_back('.');

        unordered_map<int, int> rem2idx;
        while (rem && rem2idx.find(rem) == rem2idx.end()) {
            rem2idx[rem] = ret.size();
            ret.push_back('0' + rem * 10 / b);
            rem = rem * 10 % b;
        }
        if (rem == 0) { return ret; }

        ret.insert(ret.begin() + rem2idx[rem], '(');
        ret.push_back(')');

        return ret;
    }
};
