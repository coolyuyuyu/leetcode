class Solution {
public:
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
};
