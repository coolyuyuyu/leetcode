class Solution {
public:
    struct Node {
        array<Node*, 26> childs;
        Node* fail;
        int cnt;
        Node() {
            childs.fill(nullptr);
            fail = nullptr;
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
            Node* parent = q.front();
            q.pop();

            for (int v = 0; v < 26; ++v) {
                if (parent->childs[v] == nullptr) { continue; }
                Node* child = parent->childs[v];

                if (parent == root) {
                    child->fail = root;
                }
                else {
                    Node* node = parent->fail;
                    while (node != root && node->childs[v] == nullptr) {
                        node = node->fail;
                    }
                    child->fail = node->childs[v] ? node->childs[v] : node;
                }

                q.push(child);
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

            Node* tmp = node;
            while (tmp && visited.insert(tmp).second) {
                ret += tmp->cnt;
                tmp = tmp->fail;
            }
        }

        return ret;
    }
};
