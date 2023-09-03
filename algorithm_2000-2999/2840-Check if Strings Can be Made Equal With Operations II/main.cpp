class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        vector<int> eCnts(26, 0), oCnts(26, 0);
        for (int i = 0; i < n; ++i) {
            if (i & 1) {
                ++eCnts[s1[i] - 'a'], --eCnts[s2[i] - 'a'];
            }
            else {
                ++oCnts[s1[i] - 'a'], --oCnts[s2[i] - 'a'];
            }
        }

        for (int i = 0; i < 26; ++i) {
            if (eCnts[i] || oCnts[i]) {
                return false;
            }
        }

        return true;
    }
};
