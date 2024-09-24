class Solution {
public:
    string longestWord(vector<string>& words) {
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
        root->end = true;
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

        std::function<string(Node*)> dfs = [&](Node* root) {
            if (root == nullptr) return string();

            string ret;
            for (char c = 'a'; c <= 'z'; ++c) {
                if (root->childs[c - 'a'] == nullptr) { continue; }
                if (root->childs[c - 'a']->end == false) { continue; }
                string s = c + dfs(root->childs[c - 'a']);
                if (s.size() > ret.size()) {
                    ret = s;
                }
            }

            return ret;
        };

        return dfs(root);
    }
};
