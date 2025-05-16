class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        std::function<int(int)> check = [&](int target) {
            int dp1 = 0, dp2 = 0;
            for (int i = 0; i < n; ++i) {
                if (tops[i] != target && bottoms[i] != target) { return INT_MAX; }
                if (tops[i] != target) { ++dp1; }
                if (bottoms[i] != target) { ++dp2; }
            }

            return std::min(dp1, dp2);
        };

        int ret = std::min(check(tops[0]), check(bottoms[0]));
        return ret == INT_MAX ? -1 : ret;
    }
};
