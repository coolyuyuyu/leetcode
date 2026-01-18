class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        std::function<long long(int, int)> f = [&](int i, int j) {
            int b1 = bottomLeft[i][1], l1 = bottomLeft[i][0], t1 = topRight[i][1], r1 = topRight[i][0];
            int b2 = bottomLeft[j][1], l2 = bottomLeft[j][0], t2 = topRight[j][1], r2 = topRight[j][0];
            int b = std::max(b1, b2);
            int t = std::min(t1, t2);
            int l = std::max(l1, l2);
            int r = std::min(r1, r2);
            if (b >= t || l >= r) { return 0LL; }
            int side = std::min(r - l, t - b);
            return 1LL * side * side;
        };

        long long ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ret = std::max(ret, f(i, j));
            }
        }

        return ret;
    }
};
