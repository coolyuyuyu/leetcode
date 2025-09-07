class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumE = (2 + 2 + (n - 1) * 2) * n / 2;
        int sumO = (1 + 1 + (n - 1) * 2) * n / 2;
        return std::gcd(sumE, sumO);
    }
};
