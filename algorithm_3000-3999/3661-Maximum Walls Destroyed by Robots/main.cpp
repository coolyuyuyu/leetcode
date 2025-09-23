class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();

        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; ++i) {
            pairs[i] = {robots[i], distance[i]};
        }
        sort(pairs.begin(), pairs.end());

        sort(walls.begin(), walls.end());

        pairs.insert(pairs.begin(), {INT_MIN, 0});
        pairs.insert(pairs.end(), {INT_MAX, 0});

        std::function<int(int, int)> shoot = [&](int i, int d) -> int {
            if (d == 0) { // LFT
                auto lo = std::lower_bound(walls.begin(), walls.end(), std::max(pairs[i].first - pairs[i].second, pairs[i - 1].first + 1));
                auto hi = std::upper_bound(walls.begin(), walls.end(), pairs[i].first);
                return std::distance(lo, hi);
            }
            else { // RHT
                auto lo = std::lower_bound(walls.begin(), walls.end(), pairs[i].first);
                auto hi = std::upper_bound(walls.begin(), walls.end(), std::min(pairs[i].first + pairs[i].second, pairs[i + 1].first - 1));
                return std::distance(lo, hi);
            }
        };

        std::function<int(int)> overlap = [&](int i) -> int {
            auto lo = std::lower_bound(walls.begin(), walls.end(), std::max(pairs[i].first - pairs[i].second, pairs[i - 1].first + 1));
            auto hi = std::upper_bound(walls.begin(), walls.end(), std::min(pairs[i - 1].first + pairs[i - 1].second, pairs[i].first - 1));
            return std::max<int>(std::distance(lo, hi), 0);
        };

        // dp[i][j]: the maximum number of unique walls that can be destroyed by the robots[1:i] and robots[i] shoot j direction.
        int dp[n + 1][2];
        dp[0][0] = dp[0][1] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = std::max(dp[i - 1][0] + shoot(i, 0), dp[i - 1][1] + shoot(i, 0) - overlap(i));
            dp[i][1] = std::max(dp[i - 1][0], dp[i - 1][1]) + shoot(i, 1);
        }

        return std::max(dp[n][0], dp[n][1]);
    }
};
