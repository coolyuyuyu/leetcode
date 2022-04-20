class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lineCnt = 0, charCnt = 0;
        for (char c : s) {
            int w = widths[c - 'a'];
            if (100 < (charCnt + w)) {
                ++lineCnt;
                charCnt = w;
            }
            else {
                charCnt += w;
            }
        }
        if (0 < charCnt) {
            ++lineCnt;
        }

        return {lineCnt, charCnt};
    }
};
