class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int m = source.size(), n = original.size();

        int costs[26][26];
        for (int u = 0; u < 26; ++u) {
            for (int v = 0; v < 26; ++v) {
                costs[u][v] = (u == v ? 0 : INT_MAX);
            }
        }
        for (int i = 0; i < n; ++i) {
            int u = original[i] - 'a', v = changed[i] - 'a';
            costs[u][v] = std::min(costs[u][v], cost[i]);
        }

        for (int x = 0; x < 26; ++x) {
            for (int u = 0; u < 26; ++u) {
                for (int v = 0; v < 26; ++v) {
                    if (costs[u][x] == INT_MAX || costs[x][v] == INT_MAX) { continue; }
                    costs[u][v] = std::min(costs[u][v], costs[u][x] + costs[x][v]);
                }
            }
        }

        long long ret = 0;
        for (int i = 0; i < m; ++i) {
            int cost = costs[source[i] - 'a'][target[i] - 'a'];
            if (cost == INT_MAX) { return -1; }
            ret += cost;
        }

        return ret;
    }
};
