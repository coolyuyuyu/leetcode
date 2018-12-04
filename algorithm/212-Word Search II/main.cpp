class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* pRoot = buildTrie(words);

        string result;
        vector<string> results;

        size_t rowCnt = board.size();
        size_t colCnt = board.empty() ? 0 : board.front().size();
        for (size_t row = 0; row < rowCnt; ++row) {
            for (size_t col = 0; col < colCnt; ++col) {
                findWords(board, row, col, pRoot, result, results);
            }
        }

        return results;
    }
private:
    class TrieNode {
    public:
        TrieNode()
            : childs(26, nullptr)
            , end(false) {
        }

        vector<TrieNode*> childs;
        bool end;
    };

    TrieNode* buildTrie(const vector<string>& words) {
        TrieNode* pRoot = new TrieNode();
        for (const string& word : words) {
            insert(pRoot, word);
        }

        return pRoot;
    }

    void insert(TrieNode* pRoot, const string& word) {
        TrieNode** ppNode = &pRoot;
        for (char c : word) {
            ppNode = &((*ppNode)->childs[c - 'a']);
            if (*ppNode == nullptr) {
                *ppNode = new TrieNode();
            }
        }

        (*ppNode)->end = true;
    }

    void findWords(vector<vector<char>>& board, size_t row, size_t col, TrieNode* pRoot, string& result, vector<string>& results) {
        assert(pRoot);

        pRoot = pRoot->childs[board[row][col] - 'a'];
        if (pRoot) {
            char tmp = board[row][col];
            result.push_back(board[row][col]);
            board[row][col] = NULL;

            if (pRoot->end) {
                results.push_back(result);
                pRoot->end = false;
            }

            // left
            if (0 < col && board[row][col - 1] != NULL) {
                findWords(board, row, col - 1, pRoot, result, results);
            }

            // upper
            if (0 < row && board[row - 1][col] != NULL) {
                findWords(board, row - 1, col, pRoot, result, results);
            }

            // right
            size_t colCnt = board.empty() ? 0 : board.front().size();
            if (col + 1 < colCnt && board[row][col + 1] != NULL) {
                findWords(board, row, col + 1, pRoot, result, results);
            }

            // lower
            size_t rowCnt = board.size();
            if (row + 1 < rowCnt && board[row + 1][col] != NULL) {
                findWords(board, row + 1, col, pRoot, result, results);
            }

            board[row][col] = tmp;
            result.pop_back();
        }
    }
};