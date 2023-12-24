class Solution {
public:
    // Time: O(N + E * K)
    int bfs(int n, const vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> graph[n];
        for (const auto& flight : flights) {
            int u = flight[0], v = flight[1], price = flight[2];
            graph[u].emplace_back(v, price);
        }

        int dists[n];
        std::fill(dists, dists + n, INT_MAX);
        dists[src] = 0;

        queue<pair<int, int>> q; // <city, prices>
        q.emplace(src, 0);
        for (int stops = 0; stops <= k && !q.empty(); ++stops) {
            for (int i = q.size(); 0 < i--;) {
                auto [cur, prices] = q.front();
                q.pop();

                for (const auto& [nxt, price] : graph[cur]) {
                    if (dists[nxt] <= prices + price) { continue; }
                    dists[nxt] = prices + price;

                    q.emplace(nxt, prices + price);
                }
            }
        }

        return dists[dst] == INT_MAX ? -1 : dists[dst];
    }

    // Time: O(E * min(N, K))
    int bellmanford(int n, const vector<vector<int>>& flights, int src, int dst, int k) {
        int dists[n];
        std::fill(dists, dists + n, INT_MAX / 2);
        dists[src] = 0;

        for (int i = 0; i < std::min(n - 1, k + 1); ++i) {
            bool modified = false;

            int tmps[n];
            std::copy(dists, dists + n, tmps);
            for (const auto& flight : flights) {
                int from = flight[0], to = flight[1], price = flight[2];
                if (tmps[from] + price < dists[to]) {
                    dists[to] = tmps[from] + price;
                    modified = true;
                }
            }

            if (!modified) { break; }
        }

        return dists[dst] == INT_MAX / 2 ? -1 : dists[dst];
    }

    // Time: O(N + E * K * log(E * K))
    int dijkstra(int n, const vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> graph[n];
        for (const auto& flight : flights) {
            int u = flight[0], v = flight[1], price = flight[2];
            graph[u].emplace_back(v, price);
        }

        int visited[n];
        std::fill(visited, visited + n, INT_MAX);

        auto comp = [](const tuple<int, int, int>& t1, const tuple<int, int, int>& t2) {
            return std::get<1>(t1) > std::get<1>(t2);
        };
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(comp)> pq(comp); // <city, prices, times>
        pq.emplace(src, 0, 0);
        while (!pq.empty()) {
            auto [cur, prices, times] = pq.top();
            pq.pop();

            if (visited[cur] <= times) { continue; }
            visited[cur] = times;

            if (cur == dst) {
                return prices;
            }

            for (const auto& [nxt, price] : graph[cur]) {
                if (times + 1 > k + 1) { continue; }
                if (visited[nxt] <= times + 1) { continue; }
                pq.emplace(nxt, prices + price, times + 1);
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
