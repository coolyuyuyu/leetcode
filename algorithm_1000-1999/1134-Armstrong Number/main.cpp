class Solution {
public:
    bool isArmstrong(int n) {
        int cnt = 0;
        for (int num = n; num; num /= 10) {
            ++cnt;
        }

        int arm = 0;
        for (int num = n; num; num /= 10) {
            int d = num % 10;

            int tmp = d;
            for (int i = 1; i < cnt; ++i) {
                tmp *= d;
            }
            arm += tmp;
        }

        return arm == n;
    }
};
