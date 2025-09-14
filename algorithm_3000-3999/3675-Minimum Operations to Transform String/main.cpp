class Solution {
public:
    int minOperations(string s) {
        vector<int> cnts(26, 0);
        for (char c : s) {
            ++cnts[c - 'a'];
        }

        for (int i = 1; i < 26; ++i) {
            if (cnts[i] > 0) {
                return 26 - i;
            }
        }

        return 0;
    }
};
