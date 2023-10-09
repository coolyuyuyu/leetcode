class Solution {
public:
    int minimumSum(int num) {
        vector<int> digits;
        for (int i = 0; i < 4; ++i) {
            digits.push_back(num % 10);
            num /= 10;
        }
        std::sort(digits.begin(), digits.end());

        int new1 = digits[0] * 10 + digits[3];
        int new2 = digits[1] * 10 + digits[2];
        return new1 + new2;
    }
};
