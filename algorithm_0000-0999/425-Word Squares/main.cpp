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

    class TrieNode {
    public:
        TrieNode()
            : childs(26, nullptr) {
        }

        vector<TrieNode*> childs;
        vector<size_t> indexes;
    };

    TrieNode* buildTrie(const vector<string>& words) {
        TrieNode* pRoot = new TrieNode();
        for (size_t i = 0; i < words.size(); ++i) {
            insertTrie(pRoot, words[i], i);
        }

        return pRoot;
    }

    void insertTrie(TrieNode* pRoot, const string& word, size_t index) {
        pRoot->indexes.push_back(index);

        TrieNode** ppNode = &pRoot;
        for (char c : word) {
            ppNode = &((*ppNode)->childs[c - 'a']);
            if (*ppNode == nullptr) {
                *ppNode = new TrieNode();
            }
            (*ppNode)->indexes.push_back(index);
        }
    }

    void wordSquaresTrieDfsHelper(vector<string>& words, size_t level, TrieNode* pRoot, vector<string>& result, vector<vector<string>>& results) {
        if (result.size() <= level) {
            results.push_back(result);
            return;
        }

        TrieNode* pNode = pRoot;
        for (size_t i = 0; i < level; ++i) {
            pNode = pNode->childs[result[i][level] - 'a'];
            if (!pNode) {
                return;
            }
        }

        for (size_t index : pNode->indexes) {
            result[level] = words[index];
            wordSquaresTrieDfsHelper(words, level + 1, pRoot, result, results);
        }
    }

    vector<vector<string>> wordSquaresTrieDfs(vector<string>& words) {
        size_t len = words.empty() ? 0 : words.front().size();

        TrieNode* pRoot = buildTrie(words);
        vector<string> result(len);
        vector<vector<string>> results;
        wordSquaresTrieDfsHelper(words, 0, pRoot, result, results);
        return results;
    }

    vector<vector<string>> wordSquares(vector<string>& words) {
        //return wordSquaresBruteDfs(words);

        return wordSquaresTrieDfs(words);
    }
};