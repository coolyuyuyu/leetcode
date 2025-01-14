class Solution {
public:
    int minimumLength(string s) {
        vector<int> cnts(26, 0);
        for (char c : s) {
            ++cnts[c - 'a'];
        }

        int ret = 0;
        for (int cnt : cnts) {
            if (cnt <= 2) {
                ret += cnt;
            }
            else {
                ret += ((cnt & 1) ? 1 : 2);
            }
        }

        return ret;
    }
};
