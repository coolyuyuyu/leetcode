class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits.back() += 1;
        bool carry = false;
        for (vector<int>::reverse_iterator iter = digits.rbegin(); iter != digits.rend(); ++iter) {
            if (carry) {
                *iter += 1;
                carry = false;
            }
            if (10 <= *iter) {
                *iter %= 10;
                carry = true;
            }
        }
        if (carry) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};