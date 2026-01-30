class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int costs[26][26];
        std::fill(&costs[0][0], &costs[0][0] + 26 * 26, INT_MAX / 2);

        for (int u = 0; u < 26; ++u) {
            costs[u][u] = 0;
        }
        for (int i = 0; i < original.size(); ++i) {
            int u = original[i] - 'a', v = changed[i] - 'a', w = cost[i];
            costs[u][v] = std::min(costs[u][v], w);
        }

        for (int i = 0; i < 26; ++i) {
            for (int u = 0; u < 26; ++u) {
                for (int v = 0; v < 26; ++v) {
                    costs[u][v] = std::min(costs[u][v], costs[u][i] + costs[i][v]);
                }
            }
        }

        long long ret = 0;
        for (int i = 0; i < source.size(); ++i) {
            int u = source[i] - 'a', v = target[i] - 'a';
            if (costs[u][v] >= INT_MAX / 2) {
                return -1;
            }
            ret += costs[u][v];
        }

        return ret;
    }
};
