class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = true;
        for (size_t i = digits.size(); 0 < i-- && carry;) {
            if (++digits[i] == 10) {
                digits[i] = 0;
            }
            else {
                carry = false;
            }
        }
        if (carry) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};
