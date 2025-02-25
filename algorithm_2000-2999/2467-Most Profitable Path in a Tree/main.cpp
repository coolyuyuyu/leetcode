class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size() + 1;
        vector<int> graph[n];
        for (const auto& edge : edges) {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int times[n];
        std::fill(times, times + n, INT_MAX);
        std::function<bool(int, int, int, int)> computeArrivalTime = [&](int cur, int pre, int dst, int step) {
            bool found = false;
            if (cur == dst) {
                found = true;
                times[cur] = step;
            }
            else {
                for (int nxt : graph[cur]) {
                    if (nxt == pre) { continue; }
                    if (computeArrivalTime(nxt, cur, dst, step + 1)) {
                        found = true;
                        times[cur] = step;
                        break;
                    }
                }
            }

            return found;
        };
        computeArrivalTime(bob, -1, 0, 0);

        int ret = INT_MIN;
        std::function<void(int, int, int, int)> computePathAmounts = [&](int cur, int pre, int step, int score) {
            if (step == times[cur]) {
                score += (amount[cur] / 2);
            }
            else if (step < times[cur]) {
                score += amount[cur];
            }

            bool isLeaf = true;
            for (int nxt : graph[cur]) {
                if (nxt == pre) { continue; }
                isLeaf = false;
                computePathAmounts(nxt, cur, step + 1, score);
            }
            if (isLeaf && score > ret) {
                ret = score;
            }
        };
        computePathAmounts(0, -1, 0, 0);

        return ret;
    }
};
