class Solution {
public:
    // --- dfs ---
    bool dfs(const unordered_set<string>& words, const string& s, size_t start) {
        if (s.size() <= start) {
            return true;
        }

        for (size_t i = start; i < s.size(); ++i) {
            if (words.find(s.substr(start, i - start + 1)) != words.end() && dfs(words, s, i + 1)) {
                return true;
            }
        }

        return false;
    }

    vector<string> dfs(vector<string>& words) {
        std::sort(words.begin(), words.end(), [](const string& s1, const string& s2) { return s1.size() < s2.size(); });

        unordered_set<string> dict;

        vector<string> ret;
        for (const string& word : words) {
            if (dfs(dict, word, 0)) {
                ret.push_back(word);
            }
            dict.insert(word);
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

        for (size_t i = start; i < s.size(); ++i) {
            if (words.find(s.substr(start, i - start + 1)) != words.end() && dfs_memo(words, s, i + 1, cache)) {
                return true;
            }
        }

        return cache[start] = false;
    }

    vector<string> dfs_memo(vector<string>& words) {
        std::sort(words.begin(), words.end(), [](const string& s1, const string& s2) { return s1.size() < s2.size(); });

        unordered_set<string> dict;

        vector<string> ret;
        for (const string& word : words) {
            vector<bool> cache(word.size(), true);
            if (dfs_memo(dict, word, 0, cache)) {
                ret.push_back(word);
            }
            dict.insert(word);
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

    vector<string> trie(vector<string>& words) {
        std::sort(words.begin(), words.end(), [](const string& s1, const string& s2) { return s1.size() < s2.size(); });

        TrieNode* root = new TrieNode();

        vector<string> ret;
        for (const string& word : words) {
            if (search(root, word, 0)) {
                ret.push_back(word);
            }
            addWord(root, word);
        }

        return ret;
    }

    // --- trie + memo ---
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

    vector<string> trie_memo(vector<string>& words) {
        std::sort(words.begin(), words.end(), [](const string& s1, const string& s2) { return s1.size() < s2.size(); });

        TrieNode* root = new TrieNode();

        vector<string> ret;
        for (const string& word : words) {
            vector<bool> cache(word.size(), true);
            if (search(root, word, 0, cache)) {
                ret.push_back(word);
            }
            addWord(root, word);
        }

        return ret;
    }

    // --- dp foreward ---
    bool dp_foreward(const unordered_set<string>& words, const string& s) {
        size_t n = s.size();
        vector<bool> dp(n, false); // dp[i]: s[0:i] is breakable or not by words

        for (size_t i = 0; i < n; ++i) {
            for (size_t j = i + 1; 0 < j--;) {
                if ((j == 0 || dp[j - 1]) &&
                    words.find(s.substr(j, i - j + 1)) != words.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n - 1];
    }

    vector<string> dp_foreward(vector<string>& words) {
        std::sort(words.begin(), words.end(), [](const string& s1, const string& s2) { return s1.size() < s2.size(); });

        unordered_set<string> dict;

        vector<string> ret;
        for (const string& word : words) {
            if (dp_foreward(dict, word)) {
                ret.push_back(word);
            }
            dict.insert(word);
        }

        return ret;
    }

    // --- dp backward ---
    bool dp_backward(const unordered_set<string>& words, const string& s) {
        size_t n = s.size();
        vector<bool> dp(n, false); // dp[i]: s[i:] is breakable or not by words

        for (size_t i = n; 0 < i--;) {
            for (size_t j = i; j < n; ++j) {
                if (((j + 1) == n || dp[j + 1]) &&
                    words.find(s.substr(i, j - i + 1)) != words.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }

    vector<string> dp_backward(vector<string>& words) {
        std::sort(words.begin(), words.end(), [](const string& s1, const string& s2) { return s1.size() < s2.size(); });

        unordered_set<string> dict;

        vector<string> ret;
        for (const string& word : words) {
            if (dp_backward(dict, word)) {
                ret.push_back(word);
            }
            dict.insert(word);
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
