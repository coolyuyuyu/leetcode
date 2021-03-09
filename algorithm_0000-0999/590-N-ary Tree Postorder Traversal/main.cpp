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
    void postorder_Recursive(Node* root, vector<int>& vals) {
        if (!root) {
            return;
        }

        for (Node* node : root->children) {
            postorder_Recursive(node, vals);
        }
        vals.push_back(root->val);
    }

    void postorder_Iterative(Node* root, vector<int>& vals) {
        stack<pair<Node*, bool>> stk;
        if (root) {
            stk.emplace(root, false);
        }

        while (!stk.empty()) {
            Node* node = stk.top().first;
            bool visited = stk.top().second;
            stk.pop();

            if (visited) {
                vals.push_back(node->val);
            }
            else {
                stk.emplace(node, true);
                for (size_t i = node->children.size(); 0 < i--;) {
                    stk.emplace(node->children[i], false);
                }
            }
        }
    }

    vector<int> postorder(Node* root) {
        vector<int> vals;

        //postorder_Recursive(root, vals);
        postorder_Iterative(root, vals);

        return vals;
    }
};