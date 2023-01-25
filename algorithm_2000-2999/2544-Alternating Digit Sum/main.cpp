class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int> digits;
        for (; n; n /= 10) {
            digits.push_back(n % 10);
        }

        int ret = 0;
        int sign = ((digits.size() %  2) == 0 ? -1 : 1);
        for (int digit : digits) {
            ret += (digit * sign);
            sign *= -1;
        }

        return ret;
    }
};
