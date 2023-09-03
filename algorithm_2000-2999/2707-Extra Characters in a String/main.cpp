
class Solution {
public:
    int dp_str_compare(string s, vector<string>& dictionary) {
        int n = s.size();

        // dp[i]: minimum number of extra characters left over if you break up s[i:]
        vector<int> dp(n + 1);
        dp[n] = 0;
        for (int i = n; 0 < i--;) {
            dp[i] = dp[i + 1] + 1;
            for (const string& word : dictionary) {
                if (s.compare(i, word.size(), word) == 0) {
                    dp[i] = std::min(dp[i], dp[i + word.size()]);
                }
            }
        }

        return dp[0];
    }

    class Trie {
    public:
        struct Node {
            Node()
                : end(false) {
                childs.fill(nullptr);
            }

            array<Node*, 26> childs;
            bool end;
        };

        Trie()
            : m_root(new Node()) {}

        void add(const string& word) {
            Node* node = m_root;
            for (char c : word) {
                if (node->childs[c - 'a'] == nullptr) {
                    node->childs[c - 'a'] = new Node();
                }
                node = node->childs[c - 'a'];
            }

            node->end = true;
        }

        Node* root() { return m_root; }

    private:
        Node* m_root;
    };

    int dp_trie(string s, vector<string>& dictionary) {
        int n = s.size();

        Trie trie;
        for (const string& word : dictionary) {
            trie.add(word);
        }

        // dp[i]: minimum number of extra characters left over if you break up s[i:]
        vector<int> dp(n + 1);
        dp[n] = 0;
        for (int i = n; 0 < i--;) {
            dp[i] = dp[i + 1] + 1;

            Trie::Node* node = trie.root();
            for (int j = i; j < n && node; ++j) {
                node = node->childs[s[j] - 'a'];
                if (node && node->end) {
                    dp[i] = std::min(dp[i], dp[j + 1]);
                }
            }
        }

        return dp[0];
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        //return dp_str_compare(s, dictionary);
        return dp_trie(s, dictionary);
    }
};
