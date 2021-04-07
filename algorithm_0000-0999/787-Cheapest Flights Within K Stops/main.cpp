class Solution {
public:
    int findCheapestPrice_DijkstraWithHeap(int n, const vector<vector<int>>& flights, int src, int dst, int k) {
        // graph
        vector<vector<pair<int, int>>> graph(n);
        for (const vector<int>& flight : flights) {
            graph[flight[0]].emplace_back(flight[1], flight[2]);
        }

        // tuple<int, int, int>: <distance, node, depth>>
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq; // min_heap

        // initialize with src
        pq.emplace(0, src, 0);

        // Dijkstra
        while (!pq.empty()) {
            int node = get<1>(pq.top());
            int distance = get<0>(pq.top());
            int depth = get<2>(pq.top());
            pq.pop();

            if ((k + 1) < depth) {
                continue;
            }

            if (node == dst) {
                return distance;
            }

            for (pair<int, int>& edge : graph[node]) {
                int neighbor = edge.first;
                int cost = edge.second;
                pq.emplace(distance + cost, neighbor, depth + 1);
            }
        }

        return -1;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        return findCheapestPrice_DijkstraWithHeap(n, flights, src, dst, k);
    }
};