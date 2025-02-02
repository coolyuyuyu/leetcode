class Solution {
public:
    int maxDifference(string s) {
        vector<int> cnts(26, 0);
        for (char c : s) {
            ++cnts[c - 'a'];
        }

        int oMx = INT_MIN, eMn = INT_MAX;
        for (int cnt : cnts) {
            if (cnt == 0) { continue; }
            if (cnt & 1) {
                oMx = std::max(oMx, cnt);
            }
            else {
                eMn = std::min(eMn, cnt);
            }
        }

        return oMx - eMn;
    }
};
