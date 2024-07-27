class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.size(), m = original.size();

        int costs[26][26];
        for (int u = 0; u < 26; ++u) {
            for (int v = 0; v < 26; ++v) {
                costs[u][v] = INT_MAX / 2;
            }
        }
        for (int u = 0; u < 26; ++u) {
            costs[u][u] = 0;
        }
        for (int i = 0; i < m; ++i) {
            int u = original[i] - 'a', v = changed[i] - 'a', w = cost[i];
            costs[u][v] = std::min(costs[u][v], w);
        }
        for (int k = 0; k < 26; ++k) {
            for (int u = 0; u < 26; ++u) {
                for (int v = 0; v < 26; ++v) {
                    costs[u][v] = std::min(costs[u][v], costs[u][k] + costs[k][v]);
                }
            }
        }

        long long ret = 0;
        for (int i = 0; i < n; ++i) {
            int u = source[i] - 'a', v = target[i] - 'a';
            if (costs[u][v] >= INT_MAX / 2) {
                return -1;
            }
            ret += costs[u][v];
        }

        return ret;
    }
};
