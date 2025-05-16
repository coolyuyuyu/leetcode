class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> cnts(26, 0);
        for (char c : s) {
            ++cnts[c - 'a'];
        }

        int vMax = 0, cMax = 0;
        for (char c = 'a'; c <= 'z'; ++c) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vMax = std::max(vMax, cnts[c - 'a']);
            }
            else {
                cMax = std::max(cMax, cnts[c - 'a']);
            }
        }

        return vMax + cMax;
    }
};
