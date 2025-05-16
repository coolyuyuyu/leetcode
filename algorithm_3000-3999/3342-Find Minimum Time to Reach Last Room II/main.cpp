class Solution {
public:
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size(), n = moveTime.empty() ? 0 : moveTime[0].size();

        bool visited[m][n];
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                visited[r][c] = false;
            }
        }

        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, std::greater<tuple<int, int, int, int>>> pq;
        pq.emplace(0, 0, 0, 2);
        while (!pq.empty()) {
            auto [t, r, c, cost] = pq.top();
            pq.pop();

            if (visited[r][c]) { continue; }
            visited[r][c] = true;

            if (r == m - 1 && c == n - 1) {
                return t;
            }

            for (const auto& [dr, dc] : dirs) {
                int x = r + dr, y = c + dc;
                if (x < 0 || x >= m || y < 0 || y >= n) { continue; }
                if (visited[x][y]) { continue; }
                int nxtCost = 3 - cost; 
                pq.emplace(std::max(moveTime[x][y] + nxtCost, t + nxtCost), x, y, nxtCost);
            }
        }
        __builtin_unreachable();

        return -1;
    }
};
