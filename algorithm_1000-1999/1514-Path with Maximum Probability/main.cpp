class Solution {
public:
    double dijkstra(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int, double>> graph[n];
        for (int i = 0; i < edges.size(); ++i) {
            int a = edges[i][0], b = edges[i][1];
            graph[a].emplace_back(b, succProb[i]);
            graph[b].emplace_back(a, succProb[i]);
        }

        double probs[n];
        std::fill(probs, probs + n, 0.0);

        priority_queue<pair<double, int>> pq;
        pq.emplace(1.0, start_node);
        while (!pq.empty()) {
            auto [prob, cur] = pq.top();
            pq.pop();

            if (probs[cur] != 0) { continue; }
            probs[cur] = prob;
            if (cur == end_node) { break; }

            for (const auto& [nxt, p] : graph[cur]) {
                if (probs[nxt] != 0) { continue; }
                pq.emplace(prob * p, nxt);
            }
        }

        return probs[end_node];
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        return dijkstra(n, edges, succProb, start_node, end_node);
    }
};
