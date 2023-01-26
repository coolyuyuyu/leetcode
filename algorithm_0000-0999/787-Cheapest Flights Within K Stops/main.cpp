class Solution {
public:
    // Time: O(N + E * K)
    int bfs(int n, const vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> nexts(n);
        for (const auto& flight : flights) {
            nexts[flight[0]].emplace_back(flight[1], flight[2]);
        }

        vector<int> dists(n, INT_MAX);
        dists[src] = 0;

        queue<pair<int, int>> q; // <node, dist>: the distance from src to node
        q.emplace(src, 0);
        for (int numStops = 0; numStops <= k && !q.empty(); ++numStops) {
            for (int n = q.size(); 0 < n--;) {
                auto [node, dist] = q.front();
                q.pop();

                for (auto [next, cost] : nexts[node]) {
                    if (dists[next] <= (dist + cost)) {
                        continue;
                    }
                    dists[next] = dist + cost;

                    q.emplace(next, dist + cost);
                }
            }
        }

        return dists[dst] == INT_MAX ? -1 : dists[dst];
    }

    // Time: O(E * min(N, K))
    int bellmanford(int n, const vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dists(n, INT_MAX);
        dists[src] = 0;
        for (int repetitions = std::min(n - 1, k + 1); 0 < repetitions--;) {
            vector<int> tmps(dists);
            bool modified = false;
            for (const auto& edge : flights) {
                int from = edge[0], to = edge[1], cost = edge[2];
                if (tmps[from] == INT_MAX) {
                    continue;
                }

                if ((tmps[from] + cost) < dists[to]) {
                    modified = true;
                    dists[to] = tmps[from] + cost;
                }
            }
            if (!modified) {
                break;
            }
        }

        return dists[dst] == INT_MAX ? -1 : dists[dst];
    }

    // Time: O(N + E * K * log(E * K))
    int dijkstra(int n, const vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> nexts(n);
        for (const auto& flight : flights) {
            nexts[flight[0]].emplace_back(flight[1], flight[2]);
        }

        vector<int> depths(n, INT_MAX);

        auto comp = [](const tuple<int, int, int>& t1, const tuple<int, int, int>& t2) {
            return std::get<1>(t1) > std::get<1>(t2);
        };
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(comp)> pq(comp); // <node, dist, depth>: the distance from src to node with depth
        pq.emplace(src, 0, 0);
        while (!pq.empty()) {
            auto [node, dist, depth] = pq.top();
            pq.pop();

            if ((k + 1) < depth) {
                continue;
            }
            if (depths[node] <= depth) {
                continue;
            }
            depths[node] = depth;

            if (node == dst) {
                return dist;
            }

            for (auto [next, cost] : nexts[node]) {
                pq.emplace(next, dist + cost, depth + 1);
            }
        }

        return -1;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //return bfs(n, flights, src, dst, k);
        return bellmanford(n, flights, src, dst, k);
        //return dijkstra(n, flights, src, dst, k);
    }
};
