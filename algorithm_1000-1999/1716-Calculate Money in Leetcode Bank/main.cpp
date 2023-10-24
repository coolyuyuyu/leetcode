class Solution {
public:
    int totalMoney(int n) {
        int week = n / 7;
        int rem = n % 7;

        int ret = (28 + 28 + 7 * (week - 1)) * week / 2;
        ret += ((week + 1) + (week + 1 + rem - 1)) * rem / 2;
        return ret;
    }
};
