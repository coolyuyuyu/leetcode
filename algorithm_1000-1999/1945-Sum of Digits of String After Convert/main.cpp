class Solution {
public:
    int getLucky(string s, int k) {
        int ret = 0;
        for (char c : s) {
            int x = 1 + c - 'a';
            ret += x / 10;
            ret += x % 10;
        }

        while (--k > 0) {
            int sum = 0;
            for (; ret; ret /= 10) {
                sum += ret % 10;
            }
            ret = sum;
        }

        return ret;
    }
};
