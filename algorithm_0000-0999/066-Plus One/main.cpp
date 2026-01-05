class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = true;
        for (int i = digits.size() - 1; i >= 0 && carry; --i) {
            carry = (digits[i] == 9);
            digits[i] = (digits[i] + 1) % 10;
        }
        if (carry) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};
