class Solution {
public:
    // TLE
    int byTrie(vector<string>& words, string target) {
        struct Node {
            array<Node*, 26> childs;
            Node() {
                childs.fill(nullptr);
            }
        };

        Node* root = new Node();
        for (const string& word : words) {
            Node* node = root;
            for (char c : word) {
                if (node->childs[c - 'a'] == nullptr) {
                    node->childs[c - 'a'] = new Node();
                }
                node = node->childs[c - 'a'];
            }
        }

        int n = target.size();
        int dp[n + 1]; // dp[i]: the minimum number of valid strings that can be concatenated to form target[i:]
        std::fill(dp, dp + n, INT_MAX / 2);
        dp[n] = 0;
        for (int i = n; 0 < i--;) {
            Node* node = root;
            for (int j = i; j < n; ++j) {
                node = node->childs[target[j] - 'a'];
                if (!node) {
                    break;
                }
                dp[i] = std::min(dp[i], 1 + dp[j + 1]);
            }
        }

        return dp[0] < INT_MAX / 2 ? dp[0] : -1;
    }

    // MLE
    int byAhoCorasick(vector<string>& words, string target) {
        class Node {
        public:
            array<Node*, 26> childs;
            Node* fail;
            int depth;
            Node(int d) {
                childs.fill(nullptr);
                fail = nullptr;
                depth = d;
            }
        };

        // build trie
        Node* root = new Node(0);
        for (int i = 0; i < words.size(); ++i) {
            Node* node = root;
            int d = 1;
            for (char c : words[i]) {
                if (node->childs[c - 'a'] == nullptr) {
                    node->childs[c - 'a'] = new Node(d);
                }
                node = node->childs[c - 'a'];
                ++d;
            }
        }

        // build fail link
        for (queue<Node*> q({root}); !q.empty();) {
            Node* u = q.front();
            q.pop();

            for (int i = 0; i < 26; ++i) {
                Node* v = u->childs[i];
                if (!v) { continue; }
                if (u == root) {
                    v->fail = root;
                }
                else {
                    Node* node = u->fail;
                    while (node != root && node->childs[i] == nullptr) {
                        node = node->fail;
                    }
                    v->fail = node->childs[i] ? node->childs[i] : root;
                }

                q.push(v);
            }
        }

        int n = target.size();
        target = "#" + target;
        int dp[n + 1]; // the minimum number of valid strings that can be concatenated to form target[1:i]
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = INT_MAX / 2;
        }

        unordered_map<Node*, vector<int>> cache;
        std::function<vector<int>&(Node*)> node2depths = [&](Node* node) -> vector<int>& {
            if (!node) {
                static vector<int> empty(0);
                return empty;
            }
            if (cache.find(node) != cache.end()) {
                return cache[node];
            }

            vector<int>& depths = cache[node];
            depths.push_back(node->depth);
            for (int depth : node2depths(node->fail)) {
                depths.push_back(depth);
            }

            return depths;
        };

        Node* node = root;
        for (int i = 1; i <= n; ++i) {
            int v = target[i] - 'a';
            while (node != root && node->childs[v] == nullptr) {
                node = node->fail;
            }
            if (node->childs[v]) {
                node = node->childs[v];
            }

            for (int depth : node2depths(node)) {
                dp[i] = std::min(dp[i], dp[i - depth] + 1);
            }
        }

        return dp[n] == INT_MAX / 2 ? -1 : dp[n];
    }

    int byKmp(vector<string>& words, string target) {
        std::function<vector<int>(const string&)> computeLPS = [](const string& s) {
            int n = s.size();

            // lps[i]: the maximum value k such that s[0:k-1] == s[i-k+1:i]
            vector<int> lps(n);
            lps[0] = 0;
            for (int i = 1; i < n; ++i) {
                int j = lps[i - 1];
                while (0 < j && s[j] != s[i]) {
                    j = lps[j - 1];
                }
                lps[i] = j + (s[j] == s[i] ? 1 : 0);
            }

            return lps;
        };

        int m = target.size();
        int dp[m];
        std::fill(dp, dp + m, 0);
        for (const string& word : words) {
            vector<int> lps = computeLPS(word);
            int j = 0;
            for (int i = 0; i < m; ++i) {
                while (j == word.size() || (0 < j && target[i] != word[j])) {
                    j = lps[j - 1];
                }
                j += (target[i] == word[j] ? 1 : 0);
                dp[i] = std::max(dp[i], j);
            }
        }

        int ret = 0;
        while (m > 0 && dp[m - 1] > 0) {
            m -= dp[m - 1];
            ++ret;
        }

        return m > 0 ? -1 : ret;
    }

    int minValidStrings(vector<string>& words, string target) {
        //return byTrie(words, target);
        //return byAhoCorasick(words, target);
        return byKmp(words, target);
    }
};
