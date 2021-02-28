class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> counts(52, 0);
        for (string::const_iterator iter = s.begin(); iter != s.end(); ++iter) {
            if ('a' <= *iter) {
                ++counts[*iter - 'a'];
            }
            else {
                ++counts[*iter - 'A' + 26];
            }
        }

        int sum = 0;
        bool hasOdd = false;
        for (vector<int>::const_iterator iter = counts.begin(); iter != counts.end(); ++iter) {
            if (*iter) {
                if (*iter % 2) {
                    hasOdd = true;
                    sum += (*iter - 1);
                }
                else {
                    sum += *iter;
                }
            }
        }
        if (hasOdd) {
            sum += 1;
        }

        return sum;
    }
};