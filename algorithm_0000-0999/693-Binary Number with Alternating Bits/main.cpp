class Solution {
public:
    bool hasAlternatingBits(int n) {
        n = n ^ (n >> 2);
        return (n & (n - 1)) == 0;
    }
};
