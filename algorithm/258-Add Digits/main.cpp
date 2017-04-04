class Solution {
public:
    int addDigits(int num) {
        while (10 <= num) {
            int tmp = 0;
            while (num) {
                tmp += (num % 10);
                num /= 10;
            }
            num = tmp;
        }
        return num;
    }
};