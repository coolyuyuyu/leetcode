class Solution {
public:
    vector<string> cellsInRange(string s) {
        char r1 = s[1], c1 = s[0], r2 = s[4], c2 = s[3];

        vector<string> ret;
        for (char c = c1; c <= c2; ++c) {
            for (char r = r1; r <= r2; ++r) {
                ret.push_back(string() + c + r);
            }
        }

        return ret;
    }
};
