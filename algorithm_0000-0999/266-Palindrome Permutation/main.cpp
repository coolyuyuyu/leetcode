class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> cnts(26, 0);
        for (char c : s) {
            ++cnts[c - 'a'];
        }

        int oddCnt = 0;
        for (int cnt : cnts) {
            if (cnt & 1 && ++oddCnt >= 2) {
                return false;
            }
        }

        return true;
    }
};
