class Solution {
public:
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater.empty() ? 0 : isWater[0].size();

        queue<pair<int, int>> q;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (isWater[r][c] == 1) {
                    q.emplace(r, c);
                }
                isWater[r][c] = -1;
            }
        }

        for (int h = 0; !q.empty(); ++h) {
            for (int i = q.size(); 0 < i--;) {
                auto [r, c] = q.front();
                q.pop();

                if (isWater[r][c] >= 0) { continue; }
                isWater[r][c] = h;

                for (const auto& [dr, dc] : dirs) {
                    int x = r + dr, y = c + dc;
                    if (x < 0 || x >= m || y < 0 || y >= n) { continue; }
                    if (isWater[x][y] >= 0) { continue; }
                    q.emplace(x, y);
                }
            }
        }

        return isWater;
    }
};
