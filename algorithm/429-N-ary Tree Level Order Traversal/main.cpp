/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> nodes;
        if (root) {
            nodes.push(root);
        }

        vector<vector<int>> rows;
        while (!nodes.empty()) {
            rows.emplace_back();
            vector<int>& row = rows.back();

            queue<Node*> childs;
            while (!nodes.empty()) {
                Node* node = nodes.front();
                nodes.pop();

                for (size_t i = 0; i < node->children.size(); ++i) {
                    childs.push(node->children[i]);
                }

                row.emplace_back(node->val);
            }
            nodes.swap(childs);
        }

        return rows;
    }
};
