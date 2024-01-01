class Solution {
public:
    int byDijkstra(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int m = workers.size(), n = bikes.size();

        std::function<int(int, int)> dist = [&](int i, int j) {
            return abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
        };

        bool visited[1 << n];
        std::fill(visited, visited + (1 << n), false);

        // state: binary representation of the bike assignment.
        //        if i-th bit is set, i-th bike is assigned to a worker.
        //        state of n bits are set, n bikes are assigned to the first n workers.
        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq; // <cost, state>
        pq.emplace(0, 0);
        while (!pq.empty()) {
            auto [cost, state] = pq.top();
            pq.pop();

            if (visited[state]) { continue; }
            visited[state] = true;

            int i = __builtin_popcount(state);
            if (i == m) { return cost; }
            for (int j = 0; j < n; ++j) {
                if ((state >> j) & 1) { continue; }
                int newCost = cost + dist(i, j);
                int newState = state | (1 << j);
                if (visited[newState]) { continue; }

                pq.emplace(newCost, newState);
            }
        }

        return INT_MAX;
    }

    int byDp(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int m = workers.size(), n = bikes.size();

        std::function<int(int, int)> dist = [&](int i, int j) {
            return abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
        };

        // dp[state]: binary representation of the bike assignment.
        int dp[1 << n];
        std::fill(dp, dp + (1 << n), INT_MAX);
        dp[0] = 0;
        int ret = INT_MAX;
        for (int i = 0; i < m; ++i) {
            // Gosper's hack
            int state = (1 << (i + 1)) - 1;
            while (state < (1 << n)) {
                for (int j = 0; j < n; ++j) {
                    if ((state >> j) & 1) {
                        dp[state] = std::min(dp[state], dp[state - (1 << j)] + dist(i, j));
                    }
                }

                if (i == m - 1) {
                    ret = std::min(ret, dp[state]);
                }

                int c = state & - state;
                int r = state + c;
                state = (((r ^ state) >> 2) / c) | r;
            }
        }

        return ret;
    }

    int byDfs(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int m = workers.size(), n = bikes.size();

        std::function<int(int, int)> dist = [&](int i, int j) {
            return abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
        };

        int cache[1 << n];
        std::fill(cache, cache + (1 << n), INT_MAX);

        std::function<int(int, int)> f = [&](int i, int state) {
            if (i == m) { return 0; }
            if (cache[state] != INT_MAX) { return cache[state]; }

            int& ret = cache[state];
            for (int j = 0; j < n; ++j) {
                if (((state >> j) & 1) == 0) {
                    ret = std::min(ret, dist(i, j) + f(i + 1, state | (1 << j)));
                }
            }

            return ret;
        };

        return f(0, 0);
    }

    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        //return byDfs(workers, bikes);
        //return byDijkstra(workers, bikes);
        return byDp(workers, bikes);
    }
};
