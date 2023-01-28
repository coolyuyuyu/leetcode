class Solution {
public:
    class TrieNode {
    public:
        TrieNode()
            : end(false)
            , count(0) {
            childs.fill(nullptr);
        }

        bool end;
        unsigned count;
        array<TrieNode*, 26> childs;
    };

    void addWord(TrieNode* root, const string& word) {
        for (char c : word) {
            if (root->childs[c - 'a'] == nullptr) {
                root->childs[c - 'a'] = new TrieNode();
            }
            root = root->childs[c - 'a'];
            root->count += 1;
        }
        root->end = true;
    }

    void removeWord(TrieNode* root, const string& word) {
        for (char c : word) {
            root = root->childs[c - 'a'];
            root->count -= 1;
        }
        root->end = false;
    }

    TrieNode* buildTrie(const vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& word : words) {
            addWord(root, word);
        }

        return root;
    }

    vector<array<int, 2>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* root, TrieNode* node, string& word, vector<string>& words) {
        char ch = board[r][c];
        if (ch == '\0' || node->childs[ch - 'a'] == nullptr || node->childs[ch - 'a']->count == 0) {
            return;
        }
        node = node->childs[ch - 'a'];

        board[r][c] = '\0';
        word.push_back(ch);

        if (node->end) {
            words.push_back(word);
            removeWord(root, word);
        }

        for (const auto& dir : dirs) {
            int x = r + dir[0];
            int y = c + dir[1];
            if (x < 0 || board.size() <= x || y < 0 || board[0].size() <= y) {
                continue;
            }

            dfs(board, x, y, root, node, word, words);
        }

        word.pop_back();
        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = buildTrie(words);

        string result;
        vector<string> results;
        for (int r = 0; r < board.size(); ++r) {
            for (int c = 0; c < board[0].size(); ++c) {
                dfs(board, r, c, root, root, result, results);
            }
        }

        return results;
    }
};
