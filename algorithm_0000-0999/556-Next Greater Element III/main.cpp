class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digits;
        for (; n; n /= 10) {
            digits.push_back(n % 10);
        }
        std::reverse(digits.begin(), digits.end());

        size_t i;
        for (i = digits.size(); 1 < i--;) {
            if (digits[i - 1] < digits[i]) {
                break;
            }
        }
        if (i-- == 0) {
            return -1;
        }

        size_t j;
        for (j = digits.size(); i < j--;) {
            if (digits[i] < digits[j] ) {
                break;
            }
        }
        std::swap(digits[i], digits[j]);
        std::sort(digits.begin() + i + 1, digits.end());

        long long ret = 0;
        for (int digit : digits) {
            ret = ret * 10 + digit;
        }

        return INT_MAX < ret ? -1 : ret;
    }
};
