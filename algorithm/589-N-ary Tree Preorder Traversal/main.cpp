/*
// Definition for a Node.
class Node {
public:
    int val;
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
    void preorderIter(Node* root, vector<int>& vals) {
        stack<Node*> nodes;
        if (root) {
            nodes.push(root);
        }

        while (!nodes.empty()) {
            Node* node = nodes.top();
            nodes.pop();

            vals.emplace_back(node->val);

            const vector<Node*>& childs = node->children;
            for (auto itr = childs.rbegin(); itr != childs.rend(); ++itr) {
                nodes.push(*itr);
            }
        }
    }

    void preorderRecv(Node* root, vector<int>& vals) {
        if (!root) {
            return;
        }

        vals.push_back(root->val);
        for (Node* node : root->children) {
            preorderRecv(node, vals);
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> vals;
        //preorderRecv(root, vals);
        preorderIter(root, vals);
        return vals;
    }
};