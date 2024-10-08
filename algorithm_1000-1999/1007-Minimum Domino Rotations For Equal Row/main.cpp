class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        std::function<int(int, const vector<int>&, const vector<int>&)> f = [](int target, const vector<int>& row1, const vector<int>& row2) {
            int ret = 0;
            for (int i = 0; i < row1.size(); ++i) {
                if (row1[i] == target) { continue; }
                if (row2[i] == target) { ++ret; }
                else { return INT_MAX; }
            }

            return ret;
        };

        int ret = std::min({
            f(tops[0], tops, bottoms),
            f(bottoms[0], tops, bottoms),
            f(tops[0], bottoms, tops),
            f(bottoms[0], bottoms, tops)});
        if (ret == INT_MAX) { ret = -1; }
        return ret;
    }
};
