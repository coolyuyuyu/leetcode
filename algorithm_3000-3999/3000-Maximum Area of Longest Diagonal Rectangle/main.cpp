class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxSquareDiag = 0;
        int ret = 0;
        for (const auto& dimension : dimensions) {
            int l = dimension[0], w = dimension[1];
            int squareDiag = l * l + w * w;
            int a = l * w;
            if (squareDiag > maxSquareDiag) {
                ret = a;
                maxSquareDiag = squareDiag;
            }
            else if (squareDiag == maxSquareDiag) {
                ret = std::max(ret, a);
            }
        }

        return ret;
    }
};
