class Solution {
public:
    bool winnerOfGame(string colors) {
        int aCnt = 0, bCnt = 0;
        for (int i = 0, j = 0; j <= colors.size(); ++j) {
            if (j == colors.size() || colors[i] != colors[j]) {
                cout << colors[i] << ": " << (j - i) << endl;
                int cnt = j - i;
                if (colors[i] == 'A') {
                    aCnt += (3 <= cnt ? (cnt - 2) : 0);
                }
                else {
                    bCnt += (3 <= cnt ? (cnt - 2) : 0);
                }

                i = j;
            }
        }

        return (aCnt > bCnt);
    }
};
