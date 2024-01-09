class Solution {
public:
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n = cost.size();

        vector<int> graph[n];
        for (const auto& edge : edges) {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<long long> coins(n);
        std::function<array<int, 6>(int, int)> dfs = [&](int cur, int pre) {
            // sorted: neg2 neg1... 0 ... pos1 pos2 pos3
            // {cnt, neg2, neg1, pos1, pos2, pos3}
            array<int, 6> ret = {1, 0, 0, 0, 0, 0};
            if (cost[cur] > 0) {
                ret[5] = cost[cur];
            }
            else {
                ret[1] = cost[cur];
            }
            auto& [cnt, neg2, neg1, pos1, pos2, pos3] = ret;
            for (int nxt : graph[cur]) {
                if (nxt == pre) { continue; }

                auto subtree = dfs(nxt, cur);
                cnt += subtree[0];
                for (int neg : {subtree[1], subtree[2]}) {
                    if (neg <= neg2) {
                        neg1 = neg2;
                        neg2 = neg;
                    }
                    else if (neg < neg1) {
                        neg1 = neg;
                    }
                }
                for (int pos : {subtree[3], subtree[4], subtree[5]}) {
                    if (pos >= pos3) {
                        pos1 = pos2;
                        pos2 = pos3;
                        pos3 = pos;
                    }
                    else if (pos >= pos2) {
                        pos1 = pos2;
                        pos2 = pos;
                    }
                    else if (pos > pos1) {
                        pos1 = pos;
                    }
                }
            }

            if (cnt < 3) {
                coins[cur] = 1;
            }
            else {
                coins[cur] = std::max(1LL * pos1 * pos2 * pos3, 1LL * neg2 * neg1 * pos3);
            }

            return ret;
        };
        dfs(0, -1);

        return coins; 
    }
};
