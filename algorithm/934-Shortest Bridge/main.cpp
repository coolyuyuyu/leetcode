class Solution {
public:
    void collect(vector<vector<int>>& grid, size_t r, size_t c, unordered_set<size_t>& candidates) {
        size_t rowCnt = grid.size(), colCnt = grid.empty() ? 0 : grid.front().size();
        switch (grid[r][c]) {
            case 0:
                candidates.emplace(r * colCnt + c);
                break;
            case 1:
                grid[r][c] = -1;

                // lft
                if (0 < c) {
                    collect(grid, r, c - 1, candidates);
                }

                // upr
                if (0 < r) {
                    collect(grid, r - 1, c, candidates);
                }

                // rht
                if (c + 1 < colCnt) {
                    collect(grid, r, c + 1, candidates);
                }

                // btm
                if (r + 1 < rowCnt) {
                    collect(grid, r + 1, c, candidates);
                }

                break;
            case -1:
                break;
        }
    }

    size_t shortestBridge(vector<vector<int>>& grid) {
        size_t rowCnt = grid.size(), colCnt = grid.empty() ? 0 : grid.front().size();

        unordered_set<size_t> candidates;
        bool collected = false;
        for (size_t r = 0; r < rowCnt && !collected; ++r) {
            for (size_t c = 0; c < colCnt && !collected; ++c) {
                if (grid[r][c] == 1) {
                    collect(grid, r, c, candidates);
                    collected = true;
                }
            }
        }

        size_t count = 0;
        while (!candidates.empty()) {
            unordered_set<size_t> candidatesTmp;
            for (size_t candidate : candidates) {
                size_t r = candidate / colCnt, c = candidate % colCnt;
                switch (grid[r][c]) {
                    case 0:
                        grid[r][c] = -1;

                        // lft
                        if (0 < c) {
                            candidatesTmp.emplace((r) * colCnt + (c - 1));
                        }

                        // upr
                        if (0 < r) {
                            candidatesTmp.emplace((r - 1) * colCnt + (c));
                        }

                        // rht
                        if (c + 1 < colCnt) {
                            candidatesTmp.emplace((r) * colCnt + (c + 1));
                        }

                        // btm
                        if (r + 1 < rowCnt) {
                            candidatesTmp.emplace((r + 1) * colCnt + (c));
                        }

                        break;
                    case 1:
                        return count;
                    case -1:
                        break;
                }

            }
            candidates.swap(candidatesTmp);

            ++count;
        }

        return count;
    }
};