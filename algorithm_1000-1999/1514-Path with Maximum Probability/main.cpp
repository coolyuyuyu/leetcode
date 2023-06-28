class Solution {
public:
    double bfs(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); ++i) {
            graph[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
            graph[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
        }

        vector<double> probs(n, 0.0);
        probs[start] = 1.0;
        for (queue<int> q({start}); !q.empty();) {
            int cur = q.front();
            q.pop();

            for (const auto& [nxt, weight]: graph[cur]) {
                if (probs[cur] * weight <= probs[nxt]) {
                    continue;
                }

                probs[nxt] = probs[cur] * weight;
                q.push(nxt);
            }
        }


        return probs[end];
    }

    double dijkstra(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<double, int>>> graph(n);
        for (int i = 0; i < edges.size(); ++i) {
            double cost = -std::log(succProb[i]);
            graph[edges[i][0]].emplace_back(cost, edges[i][1]);
            graph[edges[i][1]].emplace_back(cost, edges[i][0]);
        }

        vector<bool> visited(n, false);

        priority_queue<pair<double, int>, vector<pair<double, int>>, std::greater<>> pq;
        pq.emplace(0, start);
        while (!pq.empty()) {
            const auto [dist, cur] = pq.top();
            pq.pop();

            if (visited[cur] == true) {
                continue;
            }
            visited[cur] = true;

            if (cur == end) {
                return std::exp(-dist);
            }

            for (const auto& [cost, nxt] : graph[cur]) {
                if (visited[nxt]) {
                    continue;
                }

                pq.emplace(dist + cost, nxt);
            }
        }

        return 0;
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        //return bfs(n, edges, succProb, start, end);
        return dijkstra(n, edges, succProb, start, end);
    }
};
