class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<array<int, 2>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

        vector<size_t> indexes(queries.size());
        iota(indexes.begin(), indexes.end(), 0);
        sort(indexes.begin(), indexes.end(), [&queries](size_t i, size_t j) { return queries[i] < queries[j]; });

        int m = grid.size(), n = grid[0].size();
        auto comp = [&grid](const array<int, 2>& p1, const array<int, 2>& p2) {
            return grid[p1[0]][p1[1]] > grid[p2[0]][p2[1]];
        };
        priority_queue<array<int, 2>, vector<array<int, 2>>, decltype(comp)> minHeap(comp);
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        minHeap.push({0, 0});
        visited[0][0] = true;

        vector<int> ret(indexes.size(), 0);
        for (int cnt = 0,  i = 0; i < indexes.size(); ++i) {
            int barrier = queries[indexes[i]];
            while (!minHeap.empty()) {
                array<int, 2> p = minHeap.top();
                if (grid[p[0]][p[1]] >= barrier) {
                    break;
                }

                minHeap.pop();
                ++cnt;

                for (const auto& dir : dirs) {
                    int r = p[0] + dir[0], c = p[1] + dir[1];
                    if (0 <= r && r < m && 0 <= c && c < n && !visited[r][c]) {
                        minHeap.push({r, c});
                        visited[r][c] = true;
                    }
                }
            }

            ret[indexes[i]] = cnt;
        }

        return ret;
    }
};
