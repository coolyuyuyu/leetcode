class Solution {
public:
    long long lastInteger(long long n) {
        long long head = 1, step = 1;
        bool dir = false; // lft -> rht
        while (n > 1) {
            if (dir && n % 2 == 0) {
                head += step;
            }
            step *= 2;
            dir = !dir;
            n = (n + 1) / 2;
        }

        return head;
    }
};
