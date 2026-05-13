class Solution {
public:
    string convertNumber(string s) {
        vector<string> words = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

        struct TrieNode {
            std::array<TrieNode*, 26> nxts;
            int digit;
            TrieNode() {
                nxts.fill(nullptr);
                digit = -1;
            }
        };
        TrieNode* root = new TrieNode();

        std::function<void(const string&, int)> insert = [&](const string& word, int digit) {
            TrieNode* node = root;
            for (char c : word) {
                if (node->nxts[c - 'a'] == nullptr) {
                    node->nxts[c - 'a'] = new TrieNode();
                }
                node = node->nxts[c - 'a'];
            }
            node->digit = digit;
        };
        for (int i = 0; i < 10; ++i) {
            insert(words[i], i);
        }

        string ret;

        for (int i = 0, n = s.size(); i < n;) {
            TrieNode* node = root;
            for (int j = i; j < n && (node && (node->digit < 0)); ++j) {
                node = node->nxts[s[j] - 'a'];
            }

            if (node && node->digit >= 0) {
                ret += ('0' + node->digit);
                i += words[node->digit].size();
            }
            else {
                ++i;
            }
        }

        return ret;
    }
};
