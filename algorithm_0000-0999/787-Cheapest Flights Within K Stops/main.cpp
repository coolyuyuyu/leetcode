class Solution {
public:
    // Time: O(N + E * K)
    int bfs(int n, const vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> graph[n];
        for (const auto& flight : flights) {
            int from = flight[0], to = flight[1], price = flight[2];
            graph[from].emplace_back(to, price);
        }

        int dists[n];
        std::fill(dists, dists + n, INT_MAX);

        queue<pair<int, int>> q; // <city, cost>
        q.emplace(src, 0);
        for (int stops = 0; stops <= k + 1; ++stops) {
            for (int i = q.size(); 0 < i--;) {
                auto [cur, cost] = q.front();
                q.pop();

                if (cost >= dists[cur]) {
                    continue;
                }
                dists[cur] = cost;

                for (const auto& [nxt, price] : graph[cur]) {
                    q.emplace(nxt, cost + price);
                }
            }
        }

        return dists[dst] == INT_MAX ? -1 : dists[dst];
    }

    // Time: O(E * min(N, K))
    int bellmanford(int n, const vector<vector<int>>& flights, int src, int dst, int k) {
        // dp[i][j]: the minimum cost to reach j with i flights
        int dp[k + 2][n];
        for (int i = 0; i <= k + 1; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = INT_MAX / 2;
            }
        }
        dp[0][src] = 0;
        for (int i = 1; i <= k + 1; ++i) {
            for (const auto& flight : flights) {
                int from = flight[0], to = flight[1], price = flight[2];
                dp[i][to] = std::min(dp[i][to], dp[i - 1][from] + price);
            }
        }

        int ret = INT_MAX / 2;
        for (int i = 0; i <= k + 1; ++i) {
            ret = std::min(ret, dp[i][dst]);
        }

        return ret == INT_MAX / 2 ? -1 : ret;
    }

    // Time: O(N + E * K * log(E * K))
    int dijkstra(int n, const vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> graph[n];
        for (const auto& flight : flights) {
            int from = flight[0], to = flight[1], price = flight[2];
            graph[from].emplace_back(to, price);
        }

        auto comp = [](const tuple<int, int, int>& t1, const tuple<int, int, int>& t2) {
            return std::get<1>(t1) > std::get<1>(t2);
        };
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(comp)> pq(comp); // <city, cost, times>

        int visited[n];
        std::fill(visited, visited + n, INT_MAX);

        pq.emplace(src, 0, 0);
        while (!pq.empty()) {
            auto [cur, cost, times] = pq.top();
            pq.pop();

            if (cur == dst) { return cost; }
            if (times >= k + 1) { continue; }
            if (times >= visited[cur]) { continue; }
            visited[cur] = times;

            for (auto [nxt, price] : graph[cur]) {
                pq.emplace(nxt, cost + price, times + 1);
            }
        }

        return -1;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        return bfs(n, flights, src, dst, k);
        //return bellmanford(n, flights, src, dst, k);
        //return dijkstra(n, flights, src, dst, k);
    }
};
