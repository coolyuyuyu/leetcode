class Solution {
public:
    int balancedStringSplit(string s) {
        int cnt = 0, ret = 0;
        for (char c : s) {
            if (c == 'L') {
                ++cnt;
            }
            else {
                --cnt;
            }

            if (cnt == 0) {
                ++ret;
            }
        }

        return ret;
    }
};
