/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int diameter(Node* root) {
        int ret = 0;
        std::function<int(Node*)> dfs = [&](Node* root) {
            if (!root) { return 0; }

            int h1 = 0, h2 = 0;
            for (Node* child : root->children) {
                int h = dfs(child);
                if (h >= h1) {
                    h2 = h1;
                    h1 = h;
                }
                else if (h > h2) {
                    h2 = h;
                }
            }
            ret = std::max(ret, h1 + h2);
            return std::max(h1, h2) + 1;
        };
        dfs(root);

        return ret;
    }
};
