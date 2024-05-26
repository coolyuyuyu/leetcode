class Solution {
public:
    struct TrieNode {
        array<TrieNode*, 26> childs;
        bool end;
        TrieNode() {
            childs.fill(nullptr);
            end = false;
        }
    };

    void addWord(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->childs[c - 'a'] == nullptr) {
                node->childs[c - 'a'] = new TrieNode();
            }
            node = node->childs[c - 'a'];
        }
        node->end = true;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        TrieNode* root = new TrieNode();
        for (const string& word : wordDict) {
            addWord(root, word);
        }

        int n = s.size();
        bool breakables[n];
        std::fill(breakables, breakables + n, true);
        vector<string> ret;
        std::function<bool(int, vector<string>&)> dfs = [&](int start, vector<string>& words) {
            if (start >= n) {
                string sentence;
                for (const string& word : words) {
                    if (!sentence.empty()) { sentence += " "; }
                    sentence += word;
                }
                ret.push_back(sentence);
                return true;
            }

            bool& breakable = breakables[start];
            if (!breakable) { return false;}

            TrieNode* node = root;
            string word;
            for (int i = start; i < n && node; ++i) {
                node = node->childs[s[i] - 'a'];
                word += s[i];
                if (!node) { break; }
                if (node->end) {
                    words.push_back(word);
                    if (dfs(i + 1, words)) {
                        breakable = true;
                    }
                    words.pop_back();
                }
            }

            return breakable;
        };

        vector<string> words;
        dfs(0, words);

        return ret;
    }
};