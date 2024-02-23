class Solution {
public:
    class TrieNode {
    public:
        std::array<TrieNode*, 26> childs;
        bool end;

        TrieNode() {
            childs.fill(nullptr);
            end = false;
        }
    };

    int maxUniqueSplit(string s) {
        int n = s.size();

        TrieNode* root = new TrieNode();

        int ret = 0;
        std::function<void(int, int)> dfs = [&](int start, int level) {
            if (start >= n) {
                ret = std::max(ret, level);
            }

            TrieNode* node = root;
            for (int i = start; i < n; ++i) {
                if (node->childs[s[i] - 'a'] == nullptr) {
                    node->childs[s[i] - 'a'] = new TrieNode();
                }
                node = node->childs[s[i] - 'a'];

                if (node->end == false) {
                    node->end = true;
                    dfs(i + 1, level + 1);
                    node->end = false;
                }
            }
        };
        dfs(0, 0);

        return ret;
    }
};
