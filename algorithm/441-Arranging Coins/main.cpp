class Solution {
public:
    int arrangeCoins(int n) {
        long count = n;
        return (-1 + sqrt(1 + 8 * count)) / 2;
    }
};