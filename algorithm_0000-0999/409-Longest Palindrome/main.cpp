class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> cnts(256, 0);
        for (char c : s) {
            ++cnts[c];
        }

        int ret = 0;
        bool anyOdd = false;
        for (int cnt : cnts) {
            anyOdd |= cnt & 1;
            ret += cnt & ~(1);

        }
        ret += anyOdd ? 1 : 0;

        return ret;
    }
};
