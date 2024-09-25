class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        struct Node {
            std::array<Node*, 26> childs;
            int cnt;
            Node() {
                childs.fill(nullptr);
                cnt = 0;
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
                node->cnt += 1;
            }
        }

        vector<int> ret(words.size());
        for (int i = 0; i < words.size(); ++i) {
            const string& word = words[i];
            Node* node = root;

            int cnt = 0;
            for (char c : word) {
                node = node->childs[c - 'a'];
                cnt += node->cnt;
            }

            ret[i] = cnt;
        }

        return ret;
    }
};
