class Solution {
public:
    bool dfs(const string& s, vector<string>& words) {
        std::sort(words.begin(), words.end(), [](const string& s1, const string& s2) { return s1.size() < s2.size(); });

        std::function<bool(size_t)> f = [&](size_t start) -> bool {
            if (s.size() <= start) {
                return true;
            }

            for (const string& word : words) {
                if (s.size() < (start + word.size())) {
                    break;
                }
                if (s.compare(start, word.size(), word) == 0 && f(start + word.size())) {
                    return true;
                }
            }

            return false;
        };

        return f(0);
    }

    bool dfs_memo(const string& s, vector<string>& words) {
        std::sort(words.begin(), words.end(), [](const string& s1, const string& s2) { return s1.size() < s2.size(); });

        vector<bool> cache(s.size(), true);
        std::function<bool(size_t)> f = [&](size_t start) -> bool {
            if (s.size() <= start) {
                return true;
            }
            if (!cache[start]) {
                return false;
            }

            for (const string& word : words) {
                if (s.size() < (start + word.size())) {
                    break;
                }
                if (s.compare(start, word.size(), word) == 0 && f(start + word.size())) {
                    return true;
                }
            }

            return cache[start] = false;
        };

        return f(0);
    }

    struct TrieNode {
        TrieNode()
            : end(false) {
            childs.fill(nullptr);
        }

        bool end;
        array<TrieNode*, 26> childs;
    };

    void addWord(TrieNode* root, const string& word) {
        TrieNode** ppNode = &root;
        for (char c : word) {
            ppNode = &((*ppNode)->childs[c - 'a']);
            if (not *ppNode) {
                *ppNode = new TrieNode();
            }
        }

        (*ppNode)->end = true;
    }

    TrieNode* buildTrie(const vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& word : words) {
            addWord(root, word);
        }

        return root;
    }

    bool trie(const string& s, const vector<string>& words) {
        TrieNode* root = buildTrie(words);
        std::function<bool(size_t)> dfs = [&](size_t start) -> bool {
            if (s.size() <= start) {
                return true;
            }

            TrieNode* node = root;
            for (size_t i = start; i < s.size() && node; ++i) {
                node = node->childs[s[i] - 'a'];
                if (node && node->end && dfs(i + 1)) {
                    return true;
                }
            }

            return false;
        };

        return dfs(0);
    }

    bool trie_memo(const string& s, const vector<string>& words) {
        TrieNode* root = buildTrie(words);
        vector<bool> cache(s.size(), true);
        std::function<bool(size_t)> dfs = [&](size_t start) -> bool {
            if (s.size() <= start) {
                return true;
            }
            if (!cache[start]) {
                return false;
            }

            TrieNode* node = root;
            for (size_t i = start; i < s.size() && node; ++i) {
                node = node->childs[s[i] - 'a'];
                if (node && node->end && dfs(i + 1)) {
                    return true;
                }
            }

            return cache[start] = false;
        };

        return dfs(0);
    }

    bool dp_foreward(string& s, const vector<string>& words) {
        size_t n = s.size();

        s = "#" + s;

        // dp[i]: s[1:i] is breakable or not by words
        vector<bool> dp(n + 1);
        dp[0] = true;
        for (size_t i = 1; i <= n; ++i) {
            for (const string& word : words) {
                if (word.size() <= i &&
                    dp[i - word.size()] &&
                    s.compare(i - word.size() + 1, word.size(), word) == 0) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }

    bool dp_backward(const string& s, const vector<string>& words) {
        size_t n = s.size();

        // dp[i]: s[i:] is breakable or not by words
        vector<bool> dp(n + 1);
        dp[n] = true;
        for (size_t i = n; 0 < i--;) {
            for (const string& word : words) {
                if ((i + word.size()) <= n &&
                    dp[i + word.size()] &&
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
        return dfs_memo(s, wordDict);

        //return trie(s, wordDict);
        //return trie_memo(s, wordDict);

        //return dp_foreward(s, wordDict);
        //return dp_backward(s, wordDict);
    }
};
