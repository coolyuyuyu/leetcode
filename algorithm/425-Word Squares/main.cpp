class Solution {
public:
    void wordSquaresBruteDfsHelper(const vector<string>& words, size_t index, size_t end, vector<string>& result, vector<vector<string>>& results) {
        if (index >= end) {
            results.emplace_back(result);
        }
        else {
            for (size_t i = 0; i < words.size(); ++i) {
                bool ok = true;
                for (size_t j = 0; j < index; ++j) {
                    if (result[j][index] != words[i][j]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    result.emplace_back(words[i]);
                    wordSquaresBruteDfsHelper(words, index + 1, end, result, results);
                    result.pop_back();
                }
            }
        }
    }

    vector<vector<string>> wordSquaresBruteDfs(vector<string>& words) {
        if (words.empty()) {
            return {};
        }

        vector<string> result;
        vector<vector<string>> results;
        wordSquaresBruteDfsHelper(words, 0, words.front().size(), result, results);
        return results;
    }

    struct TrieNode {
        TrieNode()
            : childs(26, NULL) {
        }
        vector<TrieNode*> childs;
        vector<size_t> indexes;
    };

    TrieNode* buildTrie(const vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (size_t j = 0; j < words.size(); ++j) {
            TrieNode* node = root;
            const string& word = words[j];
            for (size_t i = 0; i < word.size(); ++i) {
                size_t index = word[i] - 'a';
                if (node->childs[index] == NULL) {
                    node->childs[index] = new TrieNode();
                }
                node = node->childs[index];
                node->indexes.emplace_back(j);
            }
            root->indexes.emplace_back(j);
        }

        return root;
    }

    void wordSquaresTrieDfsHelper(const vector<string>& words, const TrieNode* root, size_t level, vector<string>& result, vector<vector<string>>& results) {
        if (level >= result.size()) {
            results.emplace_back(result);
        }
        else {
            const TrieNode* node = root;
            for (size_t i = 0; i < level; ++i) {
                node = node->childs[result[i][level] - 'a'];
                if (!node) {
                    return;
                }
            }

            const vector<size_t>& indexes = node->indexes;
            for (size_t i = 0; i < indexes.size(); ++i) {
                result[level] = words[indexes[i]];
                wordSquaresTrieDfsHelper(words, root, level + 1, result, results);
            }
        }
    }

    vector<vector<string>> wordSquaresTrieDfs(vector<string>& words) {
        if (words.empty()) {
            return{};
        }

        TrieNode* root = buildTrie(words);

        vector<string> result(words.front().size());
        vector<vector<string>> results;
        wordSquaresTrieDfsHelper(words, root, 0, result, results);

        return results;
    }

    vector<vector<string>> wordSquares(vector<string>& words) {
        return wordSquaresTrieDfs(words);
    }

};