class Solution {
public:
    int getLucky(string s, int k) {
        int ret = 0;
        for (char c : s) {
            int num = 1 + c - 'a';
            ret += num / 10;
            ret += num % 10;
        }

        for (int i = 1; i < k; ++i) {
            int num = ret;
            ret = 0;
            while (num) {
                ret += num %10;
                num /= 10;
            }
        }

        return ret;
    }
};
