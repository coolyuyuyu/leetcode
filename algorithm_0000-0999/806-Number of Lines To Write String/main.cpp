class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int lineCnt = 0;
        int charCnt = 0;
        for (size_t i = 0; i < S.size(); ++i) {
            size_t index = S[i] - 'a';
            if (charCnt + widths[index] > 100) {
                ++lineCnt;
                charCnt = widths[index];
            }
            else {
                charCnt += widths[index];
            }
        }

        return {lineCnt + 1, charCnt};
    }
};