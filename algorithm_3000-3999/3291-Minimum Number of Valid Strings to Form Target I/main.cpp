class Solution {
public:
    struct TrieNode {
        array<TrieNode*, 26> childs;
        TrieNode() {
            childs.fill(nullptr);
        }
    };

    void addWord(TrieNode* root, const string& word) {
        for (char c : word) {
            if (root->childs[c - 'a'] == nullptr) {
                root->childs[c - 'a'] = new TrieNode();
            }
            root = root->childs[c - 'a'];
        }
    }

    int minValidStrings(vector<string>& words, string target) {
        TrieNode* root = new TrieNode();
        for (const string& word : words) {
            addWord(root, word);
        }

        int n = target.size();
        int dp[n + 1]; // dp[i]: the minimum number of valid strings that can be concatenated to form target[i:]
        std::fill(dp, dp + n, INT_MAX / 2);
        dp[n] = 0;
        for (int i = n; 0 < i--;) {
            TrieNode* node = root;
            for (int j = i; j < n; ++j) {
                node = node->childs[target[j] - 'a'];
                if (!node) {
                    break;
                }
                dp[i] = std::min(dp[i], 1 + dp[j + 1]);
            }
        }

        return dp[0] < INT_MAX / 2 ? dp[0] : -1;
    }
};
