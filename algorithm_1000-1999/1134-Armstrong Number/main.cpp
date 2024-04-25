class Solution {
public:
    bool isArmstrong(int n) {
        int cnt = 0;
        for (int x = n; x; x /= 10) {
            ++cnt;
        }

        int sum = 0;
        for (int x = n; x; x /= 10) {
            sum += pow(x % 10, cnt);
        }

        return sum == n;
    }
};
