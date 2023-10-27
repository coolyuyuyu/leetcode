class Solution {
public:
    int minimumMoves(string s) {
        int ret = 0;
        for (int i = 0; i < s.size();) {
            if (s[i] == 'X') {
                ++ret;
                i += 3;
            }
            else {
                i += 1;
            }
        }

        return ret;
    }
};
