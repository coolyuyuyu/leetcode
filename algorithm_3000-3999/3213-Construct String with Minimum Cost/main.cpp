class Solution {
public:
    // TLE
    int byTrie(string target, vector<string>& words, vector<int>& costs) {
        class Node {
        public:
            array<Node*, 26> childs;
            int cost;
            Node() {
                childs.fill(nullptr);
                cost = INT_MAX / 2;
            }
        };

        Node* root = new Node();
        for (int i = 0; i < words.size(); ++i) {
            Node* node = root;
            for (char c : words[i]) {
                if (node->childs[c - 'a'] == nullptr) {
                    node->childs[c - 'a'] = new Node();
                }
                node = node->childs[c - 'a'];
            }
            node->cost = std::min(node->cost, costs[i]);
        }

        int n = target.size();
        int dp[n + 1]; // dp[i]: the minimum cost to make s equal to target[i:]
        for (int i = 0; i < n; ++i) {
            dp[i] = INT_MAX / 2;
        }
        dp[n] = 0;

        for (int idx = n; 0 < idx--;) {
            Node* node = root;
            for (int i = idx; i < n; ++i) {
                char c = target[i];
                if (node->childs[c - 'a'] == nullptr) {
                    break;
                }
                node = node->childs[c - 'a'];
                dp[idx] = std::min(dp[idx], node->cost + dp[i + 1]);
            }
        }

        return dp[0] == INT_MAX / 2 ? -1 : dp[0];
    }

    int byAhoCorasick(string target, vector<string>& words, vector<int>& costs) {
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
            if (node->wid < 0 || costs[node->wid] > costs[i]) {
                node->wid = i;
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
                v->next = v->fail->wid >= 0 ? v->fail : v->fail->next;

                q.push(v);
            }
        }

        int n = target.size();
        target = "#" + target;
        int dp[n + 1]; // dp[i]: the minimum cost to make s equal to target[1:i]
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = INT_MAX / 2;
        }

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
            int v = target[i] - 'a';
            while (node != root && node->childs[v] == nullptr) {
                node = node->fail;
            }
            if (node->childs[v]) {
                node = node->childs[v];
            }

            for (int wid : node2wids(node)) {
                dp[i] = std::min(dp[i], dp[i - words[wid].size()] + costs[wid]);
            }
        }

        return dp[n] == INT_MAX / 2 ? -1 : dp[n];
    }

    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        //return byTrie(target, words, costs);
        return byAhoCorasick(target, words, costs);
    }
};
