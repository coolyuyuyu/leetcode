class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (encodedText.empty()) {
            return "";
        }

        int m = rows, n = encodedText.size() / rows;

        char mat[m][n];
        for (int r = 0, i = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                mat[r][c] = encodedText[i++];
            }
        }

        string ret;
        for (int i = 0; i < n; ++i) {
            int r = 0, c = i;
            for (; r < m && c < n; ++r, ++c) {
                ret += mat[r][c];
            }
        }
        while (!ret.empty() && ret.back() == ' ') {
            ret.pop_back();
        }

        return ret;
    }
};
