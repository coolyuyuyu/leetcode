class Solution {
public:
    int networkDelayTime(vector<vector<int>>& travelTimes, int N, int K) {
        vector<vector<int>> times(N + 1, vector<int>(N + 1, INT_MAX)); {
            for (size_t i = 1; i <= N; ++i) {
                times[i][i] = 0;
            }
            for (size_t i = 0; i < travelTimes.size(); ++i) {
                times[travelTimes[i][0]][travelTimes[i][1]] = travelTimes[i][2];
            }
        }

        vector<int> arriveTimes(N + 1, INT_MAX);
        arriveTimes[K] = 0;

        queue<int> nodes;
        nodes.push(K);
        while (!nodes.empty()) {
            int u = nodes.front();
            nodes.pop();

            for (int v = 1; v <= N; ++v) {
                if (u == v || times[u][v] == INT_MAX) {
                    continue;
                }

                int arriveTime = arriveTimes[u] + times[u][v];
                if (arriveTime < arriveTimes[v]) {
                    arriveTimes[v] = arriveTime;
                    nodes.push(v);
                }
            }
        }

        int maxArriveTime = *max_element(arriveTimes.begin() + 1, arriveTimes.end());
        return (maxArriveTime == INT_MAX ? -1 : maxArriveTime);
    }
};