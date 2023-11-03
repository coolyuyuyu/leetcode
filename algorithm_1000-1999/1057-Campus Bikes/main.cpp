class Solution {
public:

    vector<int> bySort(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size(), m = bikes.size();

        std::function<int(int, int)> computeDist = [&](int i, int j) {
            return std::abs(workers[i][0] - bikes[j][0]) + std::abs(workers[i][1] - bikes[j][1]);
        };

        vector<tuple<int, int, int>> tuples;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                tuples.emplace_back(computeDist(i, j), i, j);
            }
        }
        std::sort(tuples.begin(), tuples.end());

        vector<bool> usedWorkers(n, false);
        vector<bool> usedBikes(m, false);
        vector<int> ret(n);
        for (int pi = 0, k = n; pi < tuples.size() && k; ++pi) {
            const auto& [d, i, j] = tuples[pi];

            if (usedWorkers[i] || usedBikes[j]) { continue; }

            usedWorkers[i] = true;
            usedBikes[j] = true;
            ret[i] = j;
            k--;
        }

        return ret;
    }

    vector<int> byPQ(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size(), m = bikes.size();

        std::function<int(int, int)> computeDist = [&](int i, int j) {
            return std::abs(workers[i][0] - bikes[j][0]) + std::abs(workers[i][1] - bikes[j][1]);
        };

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, std::greater<>> pq;
        vector<pair<int, int>> pairs;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                pq.emplace(computeDist(i, j), i, j);
            }
        }

        vector<bool> usedWorkers(n, false);
        vector<bool> usedBikes(m, false);
        vector<int> ret(n);
        for (int k = n; k > 0;) {
            const auto [d, i, j] = pq.top();
            pq.pop();

            if (usedWorkers[i] || usedBikes[j]) { continue; }

            usedWorkers[i] = true;
            usedBikes[j] = true;
            ret[i] = j;
            k--;
        }

        return ret;
    }

    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        return bySort(workers, bikes);
        //return byPQ(workers, bikes);
    }
};
