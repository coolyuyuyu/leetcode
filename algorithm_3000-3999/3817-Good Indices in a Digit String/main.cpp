class Solution {
public:
    vector<int> goodIndices(string s) {
        vector<int> ret;

        int val = s[0] - '0';
        if (val == 0) {
            ret.push_back(0);
        }
        int size = 1;
        int pow = 10;
        for (int i = 1; i < s.size(); ++i) {
            val = 10 * val + (s[i] - '0');
            if (i == pow) {
                pow *= 10;
                ++size;
            }
            else {
                val -= pow * (s[i - size] - '0');
            }
            if (val == i) {
                ret.push_back(i);
            }
        }

        return ret;
    }
};
