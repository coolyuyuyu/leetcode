class Solution {
public:
    /*
    int getUnvisitedClosest(const vector<int>& distances, const vector<bool>& visiteds, int N) {
        assert(distances.size() == visiteds.size());

        int index = -1;
        int minDistance = INT_MAX;
        for (int i = 0; i < N; ++i) {
            if (visiteds[i]) {
                continue;
            }
            if (distances[i] < minDistance) {
                index = i;
                minDistance = distances[i];
            }
        }

        return index;
    }

    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        --K;
        vector<vector<int>> weights(N, vector<int>(N, INT_MAX)); {
            for (int i = 0; i < N; ++i) {
                weights[i][i] = 0;
            }
            for (int i = 0; i < times.size(); ++i) {
                weights[times[i][0] - 1][times[i][1] - 1] = times[i][2];
            }
        }

        vector<int> distances(N, INT_MAX);
        vector<bool> visiteds(N, false);
        int maxDistance = 0;

        distances[K] = 0;
        for (int i = 0; i < N; ++i) {
            int u = getUnvisitedClosest(distances, visiteds, N);
            if (u == -1) {
                return -1;
            }

            visiteds[u] = true;
            maxDistance = distances[u];
            for (int v = 0; v < N; ++v) {
                if (u == v || weights[u][v] == INT_MAX) {
                    continue;
                }

                int distance = distances[u] + weights[u][v];
                if (distance < distances[v]) {
                    distances[v] = distance;
                }
            }
        }

        return maxDistance;
    }
    */

    int networkDelayTime_Heap(vector<vector<int>>& times, int n, int k) {
        typedef pair<int, int> NodeDistance;

        vector<vector<pair<int, int>>> graph(n);
        for (const auto& time : times) {
            graph[time[0] - 1].emplace_back(time[1] - 1, time[2]);
        }

        set<int> visited;
        int distance = 0;

        auto comp = [](const NodeDistance& p1, const NodeDistance& p2) {
            if (p1.second == p2.second) {
                return (p1.first < p2.first);
            }
            else {
                return (p1.second > p2.second);
            }
        };
        priority_queue<NodeDistance, vector<NodeDistance>, decltype(comp)> pq(comp); // min_heap
        pq.emplace(k - 1, 0);
        while (!pq.empty()) {
            NodeDistance nd = pq.top();
            pq.pop();

            if (visited.insert(nd.first).second == false) {
                continue;
            }
            distance = nd.second;

            for (const pair<int, int>& edge : graph[nd.first]) {
                pq.emplace(edge.first, edge.second + nd.second);
            }
        }

        return (visited.size() == n ? distance : -1);
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Assume |V| nodes, |E| edges

        // Floyd-Warshall
        // Bellman-Ford
        // Dijkstra

        // Heap
        // Time: O(ElogE), Space: O(V + E)
        return networkDelayTime_Heap(times, n, k);
    }
};
