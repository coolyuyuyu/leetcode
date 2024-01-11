class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        int m = restrictions.size();

        std::sort(restrictions.begin(), restrictions.end(), [](const auto& r1, const auto& r2){ return r1[0] < r2[0]; });

        int h[m];
        h[0] = restrictions[0][1];
        for (int i = 1; i < m; ++i) {
            h[i] = std::min(restrictions[i][1], h[i - 1] + restrictions[i][0] - restrictions[i - 1][0]);
        }
        for (int i = m - 1; 0 < i--;) {
            h[i] = std::min(h[i], h[i + 1] + restrictions[i + 1][0] - restrictions[i][0]);
        }

        int ret = 0;
        for (int i = 1; i < m; ++i) {
            ret = max(ret, (h[i - 1]+h[i] - (restrictions[i - 1][0] - restrictions[i][0])) / 2);
        }
        ret = std::max(ret, h[m - 1] + n - restrictions[m - 1][0]);

        return ret;
    }
};
