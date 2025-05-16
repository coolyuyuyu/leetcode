class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes = "L" + dominoes + "R";

        string ret;
        for (int i = 0; i + 1< dominoes.size(); ) {
            int j = i + 1;
            while (j < dominoes.size() && dominoes[j] == '.') {
                ++j;
            }

            int inLen = j - i - 1;
            ret.push_back(dominoes[i]);
            if (dominoes[i] == 'L' && dominoes[j] == 'L') {
                for (int k = 0; k < inLen; ++k) {
                    ret += 'L';
                }
            }
            else if (dominoes[i] == 'L' && dominoes[j] == 'R') {
                for (int k = 0; k < inLen; ++k) {
                    ret += '.';
                }
            }
            else if (dominoes[i] == 'R' && dominoes[j] == 'L') {
                for (int k = 0; k < inLen/2; ++k) {
                    ret += 'R';
                }
                if (inLen & 1) {
                    ret += '.';
                }
                for (int k = 0; k < inLen/2; ++k) {
                    ret += 'L';
                }
            }
            else if (dominoes[i] == 'R' && dominoes[j] == 'R') {
                for (int k = 0; k < inLen; ++k) {
                    ret += 'R';
                }
            }
            i = j;
        }
        ret = ret.substr(1);

        return ret;
    }
};
