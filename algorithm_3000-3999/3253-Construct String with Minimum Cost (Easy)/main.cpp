class TrieNode {
public:
    array<TrieNode*, 26> childs;
    int cost;

    TrieNode() {
        childs.fill(nullptr);
        cost = INT_MAX;
    }
};

class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        TrieNode* root = new TrieNode();
        for (int i = 0; i < words.size(); ++i) {
            const string& word = words[i];
            int cost = costs[i];

            TrieNode* node = root;
            for (int j = 0; j < word.size(); ++j) {
                if (node->childs[word[j] - 'a'] == nullptr) {
                    node->childs[word[j] - 'a'] = new TrieNode();
                }
                node = node->childs[word[j] - 'a'];
            }
            node->cost = std::min(node->cost, cost);
        }

        int n = target.size();
        int dp[n]; // dp[i]: the minimum cost to make s equal to target[i:]
        std::fill(dp, dp + n, INT_MAX / 2);
        std::function<int(int)> dfs = [&](int idx) {
            if (idx >= n) {
                return 0;
            }

            int& ret = dp[idx];
            if (ret < INT_MAX / 2) {
                return ret;
            }
            TrieNode* node = root;
            for (int i = idx; i < n && node; ++i) {
                node = node->childs[target[i] - 'a'];
                if (node && node->cost < INT_MAX) {
                    ret = std::min(ret, node->cost + dfs(i + 1));
                }
            }

            return ret;
        };

        int ret = dfs(0);
        return ret < INT_MAX / 2 ? ret : -1;
    }
};
