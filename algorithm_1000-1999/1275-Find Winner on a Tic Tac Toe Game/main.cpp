class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> aRow(3), aCol(3), bRow(3), bCol(3);
        int aD1 = 0, aD2 = 0, bD1 = 0, bD2 = 0;
        bool a = true;
        for (auto& move : moves) {
            int r = move[0], c = move[1];
            if (a) {
                if (++aRow[r] == 3 || ++aCol[c] == 3 || (r == c && ++aD1 == 3) || (r + c == 2 && ++aD2 == 3)) {
                    return "A";
                }
            }
            else {
                if (++bRow[r] == 3 || ++bCol[c] == 3 || (r == c && ++bD1 == 3) || (r + c == 2 && ++bD2 == 3)) {
                    return "B";
                }
            }
            a = !a;
        }

        return moves.size() < 9 ? "Pending" : "Draw";
    }
};
