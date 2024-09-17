class Solution {
public:
    struct Node {
        array<Node*, 26> childs;
        Node* fail;
        Node* next;
        int cnt;
        Node() {
            childs.fill(nullptr);
            fail = nullptr;
            next = nullptr;
            cnt = 0;
        }
    };

    // Aho-Corasick
    int numOfStrings(vector<string>& patterns, string word) {
        // build trie
        Node* root = new Node();
        for (const string& pattern : patterns) {
            Node* node = root;
            for (char c : pattern) {
                int v = c - 'a';
                if (node->childs[v] == nullptr) {
                    node->childs[v] = new Node();
                }
                node = node->childs[v];
            }
            node->cnt += 1;
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
                v->next = v->fail->cnt > 0 ? v->fail : v->fail->next;

                q.push(v);
            }
        }

        int ret = 0;
        unordered_set<Node*> visited;
        Node* node = root;
        for (char c : word) {
            int v = c - 'a';
            while (node != root && node->childs[v] == nullptr) {
                node = node->fail;
            }
            if (node->childs[v]) {
                node = node->childs[v];
            }

            for (Node* cur = node; cur && visited.insert(cur).second; cur = cur->next) {
                ret += cur->cnt;
            }
        }

        return ret;
    }
};
