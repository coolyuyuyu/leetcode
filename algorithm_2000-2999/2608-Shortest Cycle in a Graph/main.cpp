class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<set<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }

        std::function<int(int, int)> findShortestPath = [&graph](int src, int dst) {
            vector<bool> done(graph.size(), false);
            done[src] = true;

            queue<int> q({src});
            for (int len = 0; !q.empty(); ++len) {
                for (int n = q.size(); 0 < n--;) {
                    int v = q.front();
                    q.pop();

                    if (v == dst) {
                        return len;
                    }

                    for (int next : graph[v]) {
                        if (done[next]) {
                            continue;
                        }
                        done[next] = true;

                        q.push(next);
                    }
                }
            }

            return -1;
        };

        int ret = INT_MAX;
        for (const auto& edge : edges) {
            graph[edge[0]].erase(edge[1]);
            graph[edge[1]].erase(edge[0]);

            int len = findShortestPath(edge[0], edge[1]);
            if (0 <= len) {
                ret = std::min(ret, len + 1);
            }

            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }

        return ret == INT_MAX ? -1 : ret;
    }
};
