class Solution {
public:
    // --- dfs ---
    // TLE
    bool dfs(const vector<string>& words, const string& s, size_t start) {
        if (s.size() <= start) {
            return true;
        }

        size_t remainlen = s.size() - start;
        for (const string& word : words) {
            if (remainlen < word.size()) {
                break;
            }
            if (s.compare(start, word.size(), word) == 0 && dfs(words, s, start + word.size())) {
                return true;
            }
        }

        return false;
    }

    bool dfs(const string& s, vector<string>& wordDict) {
        std::sort(wordDict.begin(), wordDict.end(), [](const string& s1, const string& s2) { return s1.size() < s2.size(); });
        return dfs(wordDict, s, 0);
    }

    // --- dfs + memorization ---
    bool dfs_memo(const vector<string>& words, const string& s, size_t start, vector<bool>& cache) {
        if (s.size() <= start) {
            return true;
        }
        if (!cache[start]) {
            return false;
        }

        size_t remainlen = s.size() - start;
        for (const string& word : words) {
            if (remainlen < word.size()) {
                break;
            }
            if (s.compare(start, word.size(), word) == 0 && dfs_memo(words, s, start + word.size(), cache)) {
                return true;
            }
        }

        return cache[start] = false;
    }

    bool dfs_memo(const string& s, vector<string>& wordDict) {
        std::sort(wordDict.begin(), wordDict.end(), [](const string& s1, const string& s2) { return s1.size() < s2.size(); });
        vector<bool> cache(s.size(), true);
        return dfs_memo(wordDict, s, 0, cache);
    }

    // --- trie ---
    // TLE
    class TrieNode {
    public:
        TrieNode()
            : end(false) {
            childs.fill(nullptr);
        }

        bool end;
        array<TrieNode*, 26> childs;
    };

    TrieNode* addWord(TrieNode* root, const string& word) {
        TrieNode** ppNode = &root;
        for (char c : word) {
            ppNode = &((*ppNode)->childs[c - 'a']);
            if (*ppNode == nullptr) {
                *ppNode = new TrieNode();
            }
        }

        (*ppNode)->end = true;
        return *ppNode;
    }

    TrieNode* buildTrie(const vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& word : words) {
            addWord(root, word);
        }

        return root;
    }

    bool search(const TrieNode* root, const string& s, size_t start) {
        if (s.size() <= start) {
            return true;
        }

        const TrieNode* node = root;
        for (size_t i = start; i < s.size() && node; ++i) {
            node = node->childs[s[i] - 'a'];
            if (node && node->end && search(root, s, i + 1)) {
                return true;
            }
        }

        return false;
    }

    bool trie(const string& s, const vector<string>& wordDict) {
        TrieNode* root = buildTrie(wordDict);
        return search(root, s, 0);
    }

    // --- trie + memorization ---
    bool search(const TrieNode* root, const string& s, size_t start, vector<bool>& cache) {
        if (s.size() <= start) {
            return true;
        }
        if (!cache[start]) {
            return false;
        }

        const TrieNode* node = root;
        for (size_t i = start; i < s.size() && node; ++i) {
            node = node->childs[s[i] - 'a'];
            if (node && node->end && search(root, s, i + 1, cache)) {
                return true;
            }
        }

        return cache[start] = false;
    }

    bool trie_memo(const string& s, const vector<string>& wordDict) {
        TrieNode* root = buildTrie(wordDict);
        vector<bool> cache(s.size(), true);
        return search(root, s, 0, cache);
    }

    // --- dp foreward ---
    bool dp_foreward(const string& s, vector<string>& words) {
        size_t n = s.size();
        vector<bool> dp(n, false); // dp[i]: s[0:i] is breakable or not by words

        for (size_t i = 0; i < n; ++i) {
            for (const string& word : words) {
                if (word.size() <= (i + 1) &&
                    (word.size() == (i + 1) || dp[i - word.size()]) &&
                    s.compare(i + 1 - word.size(), word.size(), word) == 0) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n - 1];
    }

    // --- dp backward ---
    bool dp_backward(const string& s, vector<string>& words) {
        size_t n = s.size();
        vector<bool> dp(n, false); // dp[i]: s[i:] is breakable or not by words

        for (size_t i = n; 0 < i--;) {
            for (const string& word : words) {
                if (word.size() <= (n - i) &&
                    (word.size() == (n - i) || dp[i + word.size()]) &&
                    s.compare(i, word.size(), word) == 0) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        //return dfs(s, wordDict);
        //return dfs_memo(s, wordDict);

        //return trie(s, wordDict);
        //return trie_memo(s, wordDict);

        //return dp_foreward(s, wordDict);
        return dp_backward(s, wordDict);
    }
};
