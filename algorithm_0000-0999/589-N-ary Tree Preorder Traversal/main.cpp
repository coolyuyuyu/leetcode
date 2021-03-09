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
    void preorder_Recursive(Node* root, vector<int>& vals) {
        if (!root) {
            return;
        }

        vals.push_back(root->val);
        for (Node* node : root->children) {
            preorder_Recursive(node, vals);
        }
    }

    void preorder_Iterative(Node* root, vector<int>& vals) {
        stack<pair<Node*, bool>> stk;
        if (root) {
            stk.emplace(root, true);
        }

        while (!stk.empty()) {
            Node* node = stk.top().first;
            bool visited = stk.top().second;
            stk.pop();

            if (visited) {
                vals.push_back(node->val);

                stk.emplace(node, false);
                for (size_t i = node->children.size(); 0 < i--;) {
                    stk.emplace(node->children[i], true);
                }
            }
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> vals;

        //preorder_Recursive(root, vals);
        preorder_Iterative(root, vals);

        return vals;
    }
};