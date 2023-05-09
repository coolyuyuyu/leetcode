class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        vector<multiset<int>> rowSets(m);
        vector<multiset<int>> colSets(n);
        vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>> rowDiffs(m);
        vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>> colDiffs(n);
        int steps;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                while (!rowDiffs[r].empty() && rowDiffs[r].top().first <= c) {
                    auto [_, diff] = rowDiffs[r].top();
                    rowDiffs[r].pop();

                    if (0 < diff) {
                        rowSets[r].insert(diff);
                    }
                    else {
                        assert(diff < 0);
                        rowSets[r].erase(rowSets[r].find(-diff));
                    }
                }
                while (!colDiffs[c].empty() && colDiffs[c].top().first <= r) {
                    auto [_, diff] = colDiffs[c].top();
                    colDiffs[c].pop();

                    if (0 < diff) {
                        colSets[c].insert(diff);
                    }
                    else {
                        assert(diff < 0);
                        colSets[c].erase(colSets[c].find(-diff));
                    }
                }

                if (r == 0 && c == 0) {
                    steps = 1;
                }
                else {
                    steps = std::min((rowSets[r].empty() ? INT_MAX : *rowSets[r].begin()), (colSets[c].empty() ? INT_MAX : *colSets[c].begin()));
                }

                if (steps < INT_MAX && 0 < grid[r][c]) {
                    rowDiffs[r].emplace(c + 1, steps + 1);
                    rowDiffs[r].emplace(c + grid[r][c] + 1, -(steps + 1));
                    colDiffs[c].emplace(r + 1, steps + 1);
                    colDiffs[c].emplace(r + grid[r][c] + 1, -(steps + 1));
                }
            }
        }

        return steps == INT_MAX ? -1 : steps;
    }
};
