class Solution {
public:
    double dijkstra_v1(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
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
            auto [prob, u] = pq.top();
            pq.pop();

            if (probs[u] > 0.0) { continue; }
            probs[u] = prob;
            if (u == end_node) { break; }

            for (const auto& [v, w] : graph[u]) {
                if (probs[v] > 0.0) { continue; }
                pq.emplace(prob * w, v);
            }
        }

        return probs[end_node];
    }

    double dijkstra_v2(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // maximize p1*p2*p3*...
        // maximize log(p1*p2*p3*...)
        // maximize log(p1) + log(p2) + log(p3) + ...
        // minimize -log(p1) - log(p2) - log(p3) - ...

        vector<pair<int, double>> graph[n];
        for (int i = 0; i < edges.size(); ++i) {
            int a = edges[i][0], b = edges[i][1];
            double w = -log(succProb[i]);
            graph[a].emplace_back(b, w);
            graph[b].emplace_back(a, w);
        }

        double costs[n];
        std::fill(costs, costs + n, -1.0);

        priority_queue<pair<double, int>, vector<pair<double, int>>, std::greater<pair<double, int>>> pq;
        pq.emplace(0.0, start_node);
        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();

            if (costs[u] >= 0.0) { continue; }
            costs[u] = cost;
            if (u == end_node) {
                return std::exp(-costs[end_node]);
            }

            for (const auto& [v, w] : graph[u]) {
                if (costs[v] >= 0.0) { continue; }
                pq.emplace(cost + w, v);
            }
        }

        return 0;
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // return dijkstra_v1(n, edges, succProb, start_node, end_node);
        return dijkstra_v2(n, edges, succProb, start_node, end_node);
    }
};
