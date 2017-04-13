class Solution {
public:
    int findComplement(int num) {
        int digit = 0;
        int tmp = num;
        while (tmp) {
            tmp >>= 1;
            ++digit;
        }

        num = ~num;

        int mask = 1 << digit;
        mask -= 1;

        return num & mask;
    }
};