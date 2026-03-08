class Solution {
public:
    bool isDigitorialPermutation(int n) {
        int f[10];
        f[0] = 1;
        for (int i = 1; i < 10; ++i) {
            f[i] = i * f[i - 1];
        }

        int sum = 0;
        for (int num = n; num; num /= 10) {
            sum += f[num % 10];
        }

        std::function<bool(int, int)> checkEqual = [](int num1, int num2) {
            vector<int> cnts1(10, 0), cnts2(10, 0);
            for (; num1; num1 /= 10) {
                ++cnts1[num1 % 10];
            }
            for (; num2; num2 /= 10) {
                ++cnts2[num2 % 10];
            }
            return cnts1 == cnts2;
        };

        return checkEqual(sum, n);
    }
};
