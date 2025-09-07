class Solution {
public:
    int byDijkstra(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int m = workers.size(), n = bikes.size();

        std::function<int(int, int)> dist = [&](int i, int j) {
            return abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
        };

        // state: the binary representation of bike assignment
        // dp[state]: the min cost of state
        int dp[1 << n];
        bool visited[1 << n];
        std::fill(visited, visited + (1 << n), false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<>> pq; // <cost, state>
        pq.emplace(0, 0);
        while (!pq.empty()) {
            auto [cost, state] = pq.top();
            pq.pop();

            if (visited[state]) { continue; };
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

    int byDFS(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int m = workers.size(), n = bikes.size();

        std::function<int(int, int)> dist = [&](int i, int j) {
            return abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
        };

        int dp[1 << n];
        std::fill(dp, dp + (1 << n), INT_MAX);

        // state: the binary representation of bike assignment
        // f(i, state): the min cost to assign available bikes (state) for workers[i:m-1]
        std::function<int(int, int)> f = [&](int i, int state) {
            if (i == m) { return 0; }
            if (dp[state] != INT_MAX) { return dp[state]; }

            int& ret = dp[state];
            for (int j = 0; j < n; ++j) {
                if (state & (1 << j)) { continue; }
                ret = std::min(ret, dist(i, j) + f(i + 1, state + (1 << j)));
            }

            return ret;
        };

        return f(0, 0);
    }

    int byDP(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int m = workers.size(), n = bikes.size();

        std::function<int(int, int)> dist = [&](int i, int j) {
            return abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
        };

        // state: the binary representation of bike assignment
        // dp[state]: the min cost of state
        int dp[1 << n];
        std::fill(dp, dp + (1 << n), INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < m; ++i) {
            // Gosper's hack: Iterate all the n-bit state where there are (i+1) 1-bits.
            for (int state = (1 << (i + 1)) - 1; state < (1 << n);) {
                for (int j = 0; j < n; ++j) {
                    if (state & (1 << j)) {
                        dp[state] = std::min(dp[state], dist(i, j) + dp[state - (1 << j)]);
                    }
                }

                int c = state & -state;
                int r = state + c;
                state = (((r ^ state) >> 2) / c) | r;
            }
        }

        int ret = INT_MAX;
        // Gosper's hack: Iterate all the n-bit state where there are m 1-bits.
        for (int state = (1 << m) - 1; state < (1 << n); ) {
            ret = std::min(ret, dp[state]);

            int c = state & -state;
            int r = state + c;
            state = (((r ^ state) >> 2) / c) | r;
        }

        return ret;
    }

    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        //return byDijkstra(workers, bikes);
        //return byDFS(workers, bikes);
        return byDP(workers, bikes);
    }
};
