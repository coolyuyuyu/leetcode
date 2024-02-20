class Solution {
public:
    struct TrieNode {
        TrieNode() {
            childs.fill(nullptr);
            cnt = 0;
        }

        array<TrieNode*, 26> childs;
        int cnt;
    };

    void add(TrieNode* root, const string& s, const unordered_set<int>& lens) {
        TrieNode* node = root;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (node->childs[c - 'a'] == nullptr) {
                node->childs[c - 'a'] = new TrieNode();
            }
            node = node->childs[c - 'a'];

            if (lens.find(i + 1) != lens.end()) {
                node->cnt += 1;
            }
        }
    }

    int find(TrieNode* root, const string& s) {
        TrieNode* node = root;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (node->childs[c - 'a'] == nullptr) {
                return 0;
            }
            node = node->childs[c - 'a'];
        }

        return node->cnt;
    }

    vector<int> computeLPS(const string& s) {
        int n = s.size();

        // lps[i]: the maximal value k such that s[0:k-1] == s[i-k+1:i]
        vector<int> lps(n);
        lps[0] = 0;
        for (int i = 1; i < n; ++i) {
            int j = lps[i - 1];
            while (j > 0 && s[j] != s[i]) {
                j = lps[j - 1];
            }
            lps[i] = j + (s[j] == s[i] ? 1 : 0);
        }

        return lps;
    }

    long long countPrefixSuffixPairs(vector<string>& words) {
        TrieNode* root = new TrieNode();

        long long ret = 0;
        for (int i = words.size(); 0 < i--;) {
            const string& word = words[i];
            int n = word.size();

            ret += find(root, word);

            vector<int> lps = computeLPS(word);
            unordered_set<int> lens;
            for (int len = lps[n - 1]; len > 0; len = lps[len - 1]) {
                lens.insert(len);
            }
            lens.insert(n);

            add(root, word, lens);
        }

        return ret;
    }
};
