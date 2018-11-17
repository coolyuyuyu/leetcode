class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int pos1 = S.size();
        int pos2 = T.size();
        do {
            --pos1;
            for (int skip = 0; 0 <= pos1 ; --pos1) {
                if (S[pos1] == '#') {
                    skip++;
                }
                else {
                    if (skip == 0) {
                        break;
                    }
                    --skip;
                }
            }

            --pos2;
            for (int skip = 0; 0 <= pos2; --pos2) {
                if (T[pos2] == '#') {
                    skip++;
                }
                else {
                    if (skip == 0) {
                        break;
                    }
                    --skip;
                }
            }

            if (pos1 >= 0 && pos2 >= 0) {
                if (S[pos1] != T[pos2]) {
                    return false;
                }
            }
        } while (pos1 >= 0 && pos2 >= 0);

        if (pos1 >= 0 && pos2 < 0) {
            return false;
        }
        else if (pos1 < 0 && pos2 >= 0) {
            return false;
        }
        else {
            return true;
        }
    }
};