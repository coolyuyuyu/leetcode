class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        class TrieNode {
        public:
            TrieNode() {
                childs.fill(nullptr);
            }
            array<TrieNode*, 26> childs;
            vector<int> indexes;
        };
        TrieNode* root = new TrieNode();

        for (int i = 0; i < words.size(); ++i) {
            TrieNode* node = root;
            for (char c : words[i]) {
                node->indexes.push_back(i);
                if (node->childs[c - 'a'] == nullptr) {
                    node->childs[c - 'a'] = new TrieNode();
                }
                node = node->childs[c - 'a'];
            }
        }

        vector<vector<string>> ret;
        vector<string> square(words[0].size());
        std::function<void(int)> dfs = [&](int lvl) {
            if (lvl >= square.size()) {
                ret.push_back(square);
                return;
            }

            TrieNode* node = root;
            for (int i = 0; i < lvl; ++i) {
                char c = square[i][lvl];
                if (node->childs[c - 'a'] == nullptr) {
                    return;
                }
                node = node->childs[c - 'a'];
            }

            for (int i : node->indexes) {
                square[lvl] = words[i];
                dfs(lvl + 1);
            }
        };
        dfs(0);

        return ret;
    }
};
