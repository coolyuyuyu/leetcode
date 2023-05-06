class Solution {
public:
    int floyd(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        map<pair<int, int>, int> pnt2id;
        vector<pair<int, int>> pnts;
        if (pnt2id.emplace(make_pair(start[0], start[1]), pnt2id.size()).second) {
            pnts.emplace_back(start[0], start[1]);
        }
        if (pnt2id.emplace(make_pair(target[0], target[1]), pnt2id.size()).second) {
            pnts.emplace_back(target[0], target[1]);
        }
        for (const auto& road : specialRoads) {
            if (pnt2id.emplace(make_pair(road[0], road[1]), pnt2id.size()).second) {
                pnts.emplace_back(road[0], road[1]);
            }
            if (pnt2id.emplace(make_pair(road[2], road[3]), pnt2id.size()).second) {
                pnts.emplace_back(road[2], road[3]);
            }
        }

        int n = pnts.size();

        int dp[n][n];
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 0;
            for (int j = i + 1; j < n; ++j) {
                dp[i][j] = dp[j][i] = abs(pnts[i].first - pnts[j].first) + abs(pnts[i].second - pnts[j].second);
            }
        }
        for (const auto& road : specialRoads) {
            int i = pnt2id[{road[0], road[1]}];
            int j = pnt2id[{road[2], road[3]}];
            dp[i][j] = std::min(dp[i][j], road[4]);
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }

        return dp[pnt2id[{start[0], start[1]}]][pnt2id[{target[0], target[1]}]];
    }

    int dijkstra(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(0, start[0], start[1]);
        for (const auto road : specialRoads) {
            pq.emplace(abs(road[2] - start[0]) + abs(road[3] - start[1]), road[2], road[3]);
        }

        int ret = INT_MAX;
        map<pair<int, int>, int> dists;
        while (!pq.empty()) {
            auto [dist, x, y] = pq.top();
            pq.pop();

            if (dists.find({x, y}) != dists.end()) {
                continue;
            }
            dists[{x, y}] = dist;

            ret = std::min(ret, dist + abs(target[0] - x) + abs(target[1] - y));

            for (const auto& road : specialRoads) {
                if (dists.find({road[2], road[3]}) != dists.end()) {
                    continue;
                }
                pq.emplace(dist + abs(road[0] - x) + abs(road[1] - y) + road[4], road[2], road[3]);
            }
        }

        return ret;
    }

    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        //return floyd(start, target, specialRoads);
        return dijkstra(start, target, specialRoads);
    }
};
