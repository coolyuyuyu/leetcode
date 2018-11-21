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
    void postorderIter(Node* root, vector<int>& vals) {
        stack<Node*> nodes;
        if (root) {
            nodes.push(root);
        }

        while (!nodes.empty()) {
            Node* node = nodes.top();
            nodes.pop();

            vals.emplace_back(node->val);

            const vector<Node*>& childs = node->children;
            for (auto itr = childs.begin(); itr != childs.end(); ++itr) {
                nodes.push(*itr);
            }
        }
        reverse(vals.begin(), vals.end());
    }

    void postorderRecv(Node* root, vector<int>& vals) {
        if (!root) {
            return;
        }

        for (Node* node : root->children) {
            postorderRecv(node, vals);
        }
        vals.push_back(root->val);
    }

    vector<int> postorder(Node* root) {
        vector<int> vals;
        postorderIter(root, vals);
        //postorderRecv(root, vals);
        return vals;
    }
};