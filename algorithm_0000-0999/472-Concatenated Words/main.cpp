class Solution {
public:
    // --- dfs ---
    bool dfs(const unordered_set<string>& words, const string& s, size_t start) {
        if (s.size() <= start) {
            return true;
        }

        for (size_t end = start + 1; (end - start) < s.size(); ++end) {
            if (words.find(s.substr(start, end - start)) != words.end() && dfs(words, s, end)) {
                return true;
            }
        }

        return false;
    }

    vector<string> dfs(const vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());

        vector<string> ret;
        for (const string& word : words) {
            if (dfs(dict, word, 0)) {
                ret.push_back(word);
            }
        }

        return ret;
    }

    // --- dfs + memo ---
    bool dfs_memo(const unordered_set<string>& words, const string& s, size_t start, vector<bool>& cache) {
        if (s.size() <= start) {
            return true;
        }
        if (!cache[start]) {
            return false;
        }

        for (size_t end = start + 1; (end - start) < s.size(); ++end) {
            if (words.find(s.substr(start, end - start)) != words.end() && dfs_memo(words, s, end, cache)) {
                return true;
            }
        }

        return cache[start] = false;
    }

    vector<string> dfs_memo(const vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());

        vector<string> ret;
        for (const string& word : words) {
            vector<bool> cache(word.size(), true);
            if (dfs_memo(dict, word, 0, cache)) {
                ret.push_back(word);
            }
        }

        return ret;
    }

    // --- trie ---
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

    bool search(TrieNode* root, const string& s, size_t start) {
        if (s.size() <= start) {
            return true;
        }

        TrieNode* node = root;
        for (size_t i = start; i < s.size() && node; ++i) {
            node = node->childs[s[i] - 'a'];
            if (node && node->end && search(root, s, i + 1)) {
                return true;
            }
        }

        return false;
    }

    vector<string> trie(const vector<string>& words) {
        size_t n = words.size();

        TrieNode* root = new TrieNode();
        vector<TrieNode*> nodes(n);
        for (size_t i = 0; i < n; ++i) {
            nodes[i] = addWord(root, words[i]);
        }

        vector<string> ret;
        for (size_t i = 0; i < n; ++i) {
            nodes[i]->end = false;
            if (search(root, words[i], 0)) {
                ret.push_back(words[i]);
            }
            nodes[i]->end = true;
        }

        return ret;
    }

    // --- trie + memo ---
    bool search(TrieNode* root, const string& s, size_t start, vector<bool>& cache) {
        if (s.size() <= start) {
            return true;
        }
        if (!cache[start]) {
            return false;
        }

        TrieNode* node = root;
        for (size_t i = start; i < s.size() && node; ++i) {
            node = node->childs[s[i] - 'a'];
            if (node && node->end && search(root, s, i + 1, cache)) {
                return true;
            }
        }

        return cache[start] = false;
    }

    vector<string> trie_memo(const vector<string>& words) {
        size_t n = words.size();

        TrieNode* root = new TrieNode();
        vector<TrieNode*> nodes(n);
        for (size_t i = 0; i < n; ++i) {
            nodes[i] = addWord(root, words[i]);
        }

        vector<string> ret;
        for (size_t i = 0; i < n; ++i) {
            nodes[i]->end = false;
            vector<bool> cache(words[i].size(), true);
            if (search(root, words[i], 0)) {
                ret.push_back(words[i]);
            }
            nodes[i]->end = true;
        }

        return ret;
    }

    // --- dp foreward ---
    bool dp_foreward(const unordered_set<string>& words, const string& s) {
        size_t n = s.size();
        vector<bool> dp(n, false); // dp[i]: s[0:i] is breakable or not by words

        for (size_t rht = 0; rht < n; ++rht) {
            for (size_t lft = rht + 1, lftMost = ((rht + 1) == n ? 1 : 0); lftMost < lft--;) {
                if ((lft == 0 || dp[lft - 1]) &&
                    words.find(s.substr(lft, rht - lft + 1)) != words.end()) {
                    dp[rht] = true;
                    break;
                }
            }
        }

        return dp[n - 1];
    }

    vector<string> dp_foreward(const vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());

        vector<string> ret;
        for (const string& word : words) {
            if (dp_foreward(dict, word)) {
                ret.push_back(word);
            }
        }

        return ret;
    }

    // --- dp backward ---
    bool dp_backward(const unordered_set<string>& words, const string& s) {
        size_t n = s.size();
        vector<bool> dp(n, false); // dp[i]: s[i:] is breakable or not by words

        for (size_t rht = n; 0 < rht--;) {
            if (rht == (n - 1) || dp[rht + 1]) {
                for (size_t lft = rht + 1, lftMost = ((rht + 1) == n ? 1 : 0); lftMost < lft--;) {
                    if (!dp[lft] &&
                        ((rht + 1) == n || dp[rht + 1]) &&
                        words.find(s.substr(lft, rht - lft + 1)) != words.end()) {
                        dp[lft] = true;
                    }
                }
            }
        }

        return dp[0];
    }

    vector<string> dp_backward(const vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());

        vector<string> ret;
        for (const string& word : words) {
            if (dp_backward(dict, word)) {
                ret.push_back(word);
            }
        }

        return ret;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        //return dfs(words);
        //return dfs_memo(words);

        //return trie(words);
        //return trie_memo(words);

        //return dp_foreward(words);
        return dp_backward(words);
    }
};
