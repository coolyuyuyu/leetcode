class Solution {
public:
    int fib(int n) {
        if (n == 0) {
            return 0;
        }
        else if (n == 1) {
            return 1;
        }

        int x = 1, y = 0;
        for (size_t i = 2; i <= n; ++i) {
            int tmp = x + y;
            y = x;
            x = tmp;
        }

        return x;
    }
};
