class Solution {
public:
    // TLE
    bool dfs(const vector<string>& words, const string& s, size_t index = 0) {
        if (s.size() <= index) {
            return true;
        }

        for (const string& word : words) {
            if (s.compare(index, word.size(), word) == 0 && dfs(words, s, index + word.size())) {
                return true;
            }
        }

        return false;
    }

    bool dfs_memo(const vector<string>& words, const string& s, size_t index, vector<bool>& cache) {
        if (s.size() <= index) {
            return true;
        }
        if (!cache[index]) {
            return false;
        }

        for (const string& word : words) {
            if (s.compare(index, word.size(), word) == 0 && dfs_memo(words, s, index + word.size(), cache)) {
                return true;
            }
        }

        return cache[index] = false;
    }

    bool dfs_memo(const vector<string>& words, const string& s) {
        vector<bool> cahce(s.size(), true);
        return dfs_memo(words, s, 0, cahce);
    }

    class TrieNode {
    public:
        TrieNode() {
            childs.fill(nullptr);
            end = false;
        }

        array<TrieNode*, 26> childs;
        bool end;
    };

    TrieNode* buildTrie(const vector<string>& words) {
        TrieNode* root = new TrieNode;
        for (const string& word : words) {
            TrieNode* node = root;
            for (char c : word) {
                if (node->childs[c - 'a'] == nullptr) {
                    node->childs[c - 'a'] = new TrieNode;
                }
                node = node->childs[c - 'a'];
            }
            node->end = true;
        }

        return root;
    }

    bool trie(TrieNode* root, const string& s, size_t index = 0) {
        if (s.size() <= index) {
            return true;
        }

        TrieNode* node = root;
        for (size_t i = index; i < s.size() && node; ++i) {
            node = node->childs[s[i] - 'a'];
            if (node && node->end && trie(root, s, i + 1)) {
                return true;
            }
        }

        return false;
    }

    // TLE
    bool trie(const vector<string>& words, const string& s) {
        return trie(buildTrie(words), s);
    }

    bool trie_memo(TrieNode* root, const string& s, size_t index, vector<bool>& cache) {
        if (s.size() <= index) {
            return true;
        }
        if (!cache[index]) {
            return false;
        }

        TrieNode* node = root;
        for (size_t i = index; i < s.size() && node; ++i) {
            node = node->childs[s[i] - 'a'];
            if (node && node->end && trie_memo(root, s, i + 1, cache)) {
                return true;
            }
        }

        return cache[index] = false;
    }

    bool trie_memo(const vector<string>& words, const string& s) {
        vector<bool> cache(s.size(), true);
        return trie_memo(buildTrie(words), s, 0, cache);
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        //return dfs(wordDict, s);
        //return dfs_memo(wordDict, s);
        //return trie(wordDict, s);
        return trie_memo(wordDict, s);
    }
};
