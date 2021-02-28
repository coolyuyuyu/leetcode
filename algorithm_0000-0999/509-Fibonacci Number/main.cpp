class Solution {
public:
    int fib(int N) {
        if (N == 0) {
            return 0;
        }
        else if (N <= 2) {
            return 1;
        }

        int f = 1;
        for (int i = 3, x = 1; i <= N; ++i) {
            int tmp = f;
            f = f + x;
            x = tmp;
        }
        return f;
    }
};