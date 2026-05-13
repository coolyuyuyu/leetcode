class Solution {
public:
    struct TrieNode {
        array<TrieNode*, 26> nxts;
        TrieNode() {
            nxts.fill(nullptr);
        }
    };

    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        TrieNode* root = new TrieNode();
        std::function<void(const string&)> add = [&](const string& word) {
            TrieNode* cur = root;
            for (char c : word) {
                if (cur->nxts[c - 'a'] == nullptr) {
                    cur->nxts[c - 'a'] = new TrieNode();
                }
                cur = cur->nxts[c - 'a'];
            }
        };

        for (const string& word : dictionary) {
            add(word);
        }

        std::function<bool(TrieNode*, const string&, int, int)> match = [&](TrieNode* cur, const string& word, int i, int k) {
            if (cur == nullptr) { return false; }
            if (k < 0) { return false; }
            if (i >= word.size()) { return true; }

            for (char c = 'a'; c <= 'z'; ++c) {
                if (cur->nxts[c - 'a'] == nullptr) { continue; }
                if (match(cur->nxts[c - 'a'], word, i + 1, k - (c != word[i]))) {
                    return true;
                }
            }
            return false;

        };

        vector<string> ret;
        for (const string& query : queries) {
            if (match(root, query, 0, 2)) {
                ret.push_back(query);
            }
        }

        return ret;
    }
};
