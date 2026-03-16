class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int r1 = coordinate1[0] - 'a', c1 = coordinate1[1] - '1';
        int r2 = coordinate2[0] - 'a', c2 = coordinate2[1] - '1';
        return ((r1 + c1) & 1) == ((r2 + c2) & 1);
    }
};
