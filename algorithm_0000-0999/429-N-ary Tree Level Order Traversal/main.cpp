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
    void levelOrder_Recursive(Node* root, vector<vector<int>>& ret, int depth = 0) {
        if (!root) {
            return;
        }

        if (ret.size() <= depth) {
            ret.resize(depth + 1);
        }
        ret[depth].push_back(root->val);

        for (Node* child : root->children) {
            levelOrder_Recursive(child, ret, depth + 1);
        }
    }

    void levelOrder_Iterative(Node* root, vector<vector<int>>& ret) {
        queue<Node*> q;
        if (root) {
            q.push(root);
        }
        while (!q.empty()) {
            ret.emplace_back(0);
            for (size_t i = q.size(); 0 < i; --i) {
                Node* node = q.front();
                q.pop();

                ret.back().push_back(node->val);

                for (Node* child : node->children) {
                    q.push(child);
                }
            }

        }
    }

    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;

        //levelOrder_Recursive(root, ret);
        levelOrder_Iterative(root, ret);

        return ret;
    }
};