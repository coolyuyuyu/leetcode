class Solution {
public:
    int byStrcmp(string s, vector<string>& words) {
        int n = s.size();

        int dp[n + 1]; // dp[i]: minimum number of extra characters left over if you break up s[i:]
        dp[n] = 0;
        for (int i = n; 0 < i--;) {
            dp[i] = dp[i + 1] + 1;
            for (const string& word : words) {
                if (s.compare(i, word.size(), word) == 0) {
                    dp[i] = std::min(dp[i], dp[i + word.size()]);
                }
            }
        }

        return dp[0];
    }

    int byTrie(string s, vector<string>& words) {
        class Node {
        public:
            array<Node*, 26> childs;
            bool end;
            Node() {
                childs.fill(nullptr);
                end = false;
            }
        };

        // build trie
        Node* root = new Node();
        for (int i = 0; i < words.size(); ++i) {
            Node* node = root;
            for (char c : words[i]) {
                if (node->childs[c - 'a'] == nullptr) {
                    node->childs[c - 'a'] = new Node();
                }
                node = node->childs[c - 'a'];
            }
            node->end = true;
        }

        int n = s.size();

        int dp[n + 1]; // dp[i]: minimum number of extra characters left over if you break up s[i:]
        dp[n] = 0;
        for (int i = n; 0 < i--;) {
            dp[i] = dp[i + 1] + 1;
            Node* node = root;
            for (int j = i; j < n && node; ++j) {
                node = node->childs[s[j] - 'a'];
                if (node && node->end) {
                    dp[i] = std::min(dp[i], dp[j + 1]);
                }
            }
        }

        return dp[0];
    }

    int byAhoCorasick(string s, vector<string>& words) {
        class Node {
        public:
            array<Node*, 26> childs;
            Node* fail;
            Node* next;
            int wid;
            Node() {
                childs.fill(nullptr);
                fail = nullptr;
                next = nullptr;
                wid = -1;
            }
        };

        // build trie
        Node* root = new Node();
        for (int i = 0; i < words.size(); ++i) {
            Node* node = root;
            for (char c : words[i]) {
                if (node->childs[c - 'a'] == nullptr) {
                    node->childs[c - 'a'] = new Node();
                }
                node = node->childs[c - 'a'];
            }
            node->wid = i;
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
                v->next = v->fail->wid >= 0 ? v->fail : v->fail->next;

                q.push(v);
            }
        }

        int n = s.size();
        s = "#" + s;
        int dp[n + 1]; // dp[i]: minimum number of extra characters left over if you break up s[1:i]
        dp[0] = 0;

        unordered_map<Node*, vector<int>> cache;
        std::function<vector<int>&(Node*)> node2wids = [&](Node* node) -> vector<int>& {
            if (!node) {
                static vector<int> empty(0);
                return empty;
            }
            if (cache.find(node) != cache.end()) {
                return cache[node];
            }

            vector<int>& wids = cache[node];
            if (node->wid >= 0) {
                wids.push_back(node->wid);
            }
            for (int wid : node2wids(node->next)) {
                wids.push_back(wid);
            }

            return wids;
        };

        Node* node = root;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + 1;

            int v = s[i] - 'a';
            while (node != root && node->childs[v] == nullptr) {
                node = node->fail;
            }
            if (node->childs[v]) {
                node = node->childs[v];
            }

            for (int wid : node2wids(node)) {
                dp[i] = std::min(dp[i], dp[i - words[wid].size()]);
            }
        }

        return dp[n];
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        //return byStrcmp(s, dictionary);
        return byTrie(s, dictionary);
        //return byAhoCorasick(s, dictionary);
    }
};
