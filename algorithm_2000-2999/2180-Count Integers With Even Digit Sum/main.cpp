class Solution {
public:
    int countEven(int num) {
        std::function<int(int)> sumDigit = [](int num) {
            int sum = 0;
            for (; num; num /= 10) {
                sum += num % 10;
            }
            return sum;
        };

        int ret = 0;
        for (int i = 1; i <= num; ++i) {
            if (sumDigit(i) % 2 == 0) {
                ++ret;
            }
        }

        return ret;
    }
};
