class Solution {
public:
    struct TrieNode {
        std::array<TrieNode*, 26> childs;
        int id;
        TrieNode() {
            childs.fill(nullptr);
            id = -1;
        }
    };

    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        int n = source.size(), m = original.size();
        unordered_map<string, int> str2id;
        for (int j = 0; j < m; ++j) {
            str2id.emplace(original[j], str2id.size());
            str2id.emplace(changed[j], str2id.size());
        }

        TrieNode* root = new TrieNode();
        for (const auto& [str, id] : str2id) {
            TrieNode* node = root;
            for (int j = str.size(); 0 < j--;) {
                if (node->childs[str[j] - 'a'] == nullptr) {
                    node->childs[str[j] - 'a'] = new TrieNode();
                }
                node = node->childs[str[j] - 'a'];
            }
            node->id = id;
        }

        long long dists[str2id.size()][str2id.size()];
        for (int u = 0; u < str2id.size(); ++u) {
            for (int v = 0; v < str2id.size(); ++v) {
                if (u == v) { dists[u][v] = 0;}
                else { dists[u][v] = LLONG_MAX / 2; }
            }
        }
        for (int j = 0; j < m; ++j) {
            int u = str2id[original[j]], v = str2id[changed[j]];
            dists[u][v] = std::min<long long>(dists[u][v], cost[j]);
        }
        for (int x = 0; x < str2id.size(); ++x) {
            for (int u = 0; u < str2id.size(); ++u) {
                for (int v = 0; v < str2id.size(); ++v) {
                    dists[u][v] = std::min(dists[u][v], dists[u][x] + dists[x][v]);
                }
            }
        }

        source.insert(source.begin(), '#');
        target.insert(target.begin(), '#');

        // dp[i]: the minimum cost to convert source[1:i] to target[1:i]
        long long dp[n + 1];
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = source[i] == target[i] ? dp[i - 1] : LLONG_MAX / 2;
            TrieNode *node1 = root, *node2 = root;
            for (int j = i; j >= 1; --j) {
                node1 = node1->childs[source[j] - 'a'];
                node2 = node2->childs[target[j] - 'a'];
                if (node1 == nullptr || node2 == nullptr) { break; }
                int id1 = node1->id, id2 = node2->id;
                if (id1 >= 0 && id2 >= 0) {
                    dp[i] = std::min(dp[i], dp[j - 1] + dists[id1][id2]);
                }
            }
        }

        return dp[n] != LLONG_MAX / 2? dp[n] : -1;
    }
};
