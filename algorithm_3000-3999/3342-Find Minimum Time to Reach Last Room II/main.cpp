class Solution {
public:
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size(), n = moveTime.empty() ? 0 : moveTime[0].size();

        bool dones[m][n];
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                dones[r][c] = false;
            }
        }

        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, std::greater<tuple<int, int, int, int>>> pq; // <time, r, c>
        pq.emplace(0, 0, 0, 2);
        while (!pq.empty()) {
            auto [t, r, c, cost] = pq.top();
            pq.pop();

            if (dones[r][c]) {
                continue;
            }
            dones[r][c] = true;

            if (r == m - 1 && c == n - 1) {
                return t;
            }

            for (const auto& [dr, dc] : dirs) {
                int x = r + dr, y = c + dc;
                if (x < 0 || x >= m || y < 0 || y >= n) { continue; }
                if (dones[x][y]) { continue; }
                int nxtCost = (cost == 1 ? 2 : 1);
                pq.emplace(std::max(t + nxtCost, moveTime[x][y] + nxtCost), x, y, nxtCost);
            }
        }
        __builtin_unreachable();

        return -1;
    }
};
