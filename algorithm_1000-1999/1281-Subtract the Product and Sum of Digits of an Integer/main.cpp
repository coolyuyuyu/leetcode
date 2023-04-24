class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1, sum = 0;
        for (; n; n /= 10) {
            int d = n % 10;
            product *= d;
            sum += d;
        }

        return (product - sum);
    }
};
