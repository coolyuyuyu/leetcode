class Solution {
public:
    int maxProduct(int n) {
        int a = 0, b = 0;
        for (; n; n /= 10) {
            int d = n % 10;
            if (d >= a) {
                b = a, a = d;
            }
            else if (d > b) {
                b = d;
            }
        }

        return a * b;
    }
};
