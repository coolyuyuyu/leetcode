class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> rowCols[n + 1], colRows[n + 1];
        for (const auto& building : buildings) {
            int x = building[0], y = building[1];
            rowCols[y].push_back(x);
            colRows[x].push_back(y);
        }
        for (int i = 1; i <= n; ++i) {
            std::sort(rowCols[i].begin(), rowCols[i].end());
            std::sort(colRows[i].begin(), colRows[i].end());
        }

        int ret = 0;
        for (const auto& building : buildings) {
            int x = building[0], y = building[1];
            int id1 = std::distance(rowCols[y].begin(), std::lower_bound(rowCols[y].begin(), rowCols[y].end(), x));
            if (id1 == 0 || (id1 + 1) == rowCols[y].size()) { continue; }
            int id2 = std::distance(colRows[x].begin(), std::lower_bound(colRows[x].begin(), colRows[x].end(), y));
            if (id2 == 0 || (id2 + 1) == colRows[x].size()) { continue; }

            ++ret;
        }

        return ret;
    }
};
