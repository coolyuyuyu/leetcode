class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        int n = source.size(), m = original.size();
        unordered_map<string, int> str2id;
        for (int j = 0; j < m; ++j) {
            str2id.emplace(original[j], str2id.size());
            str2id.emplace(changed[j], str2id.size());
        }

        long long costs[str2id.size()][str2id.size()];
        std::fill(&costs[0][0], &costs[0][0] + str2id.size() * str2id.size(), LLONG_MAX / 2);
        for (int u = 0; u < str2id.size(); ++u) {
            costs[u][u] = 0;
        }
        for (int j = 0; j < m; ++j) {
            int u = str2id[original[j]], v = str2id[changed[j]];
            long long w = cost[j];
            costs[u][v] = std::min(costs[u][v], w);
        }
        for (int x = 0; x < str2id.size(); ++x) {
            for (int u = 0; u < str2id.size(); ++u) {
                for (int v = 0; v < str2id.size(); ++v) {
                    costs[u][v] = std::min(costs[u][v], costs[u][x] + costs[x][v]);
                }
            }
        }

        struct TrieNode {
            array<TrieNode*, 26> nxts;
            int id;
            TrieNode() {
                nxts.fill(nullptr);
                id = -1;
            }
        };
        TrieNode* root = new TrieNode();
        for (const auto& [str, id] : str2id) {
            TrieNode* node = root;
            for (int i = str.size(); 0 < i--;) {
                if (node->nxts[str[i] - 'a'] == nullptr) {
                    node->nxts[str[i] - 'a'] = new TrieNode();
                }
                node = node->nxts[str[i] - 'a'];
            }
            node->id = id;
        }

        source = "#" + source;
        target = "#" + target;

        // dp[i]: the minimum cost to convert the string source[1:i] to the string target[1:j]
        long long dp[n + 1];
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = (source[i] == target[i] ? dp[i - 1] : LLONG_MAX / 2);
            TrieNode *node1 = root, *node2 = root;
            for (int j = i; j >= 1; j--) {
                node1 = node1->nxts[source[j] - 'a'];
                node2 = node2->nxts[target[j] - 'a'];
                if (!node1 || !node2) { break; }
                if (node1->id >= 0 && node2->id >= 0) {
                    dp[i] = std::min(dp[i], dp[j - 1] + costs[node1->id][node2->id]);
                }
            }
        }

        return dp[n] != LLONG_MAX / 2 ? dp[n] : -1;
    }
};
