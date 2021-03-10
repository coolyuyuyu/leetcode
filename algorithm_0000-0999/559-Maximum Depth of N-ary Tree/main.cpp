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
    int maxDepth_Recursive(Node* root, int depth = 0) {
        if(!root) {
            return depth;
        }
        else {
            int maxDepth = depth + 1;
            for (Node* child : root->children) {
                maxDepth = max(maxDepth, maxDepth_Recursive(child, depth + 1));
            }
            return maxDepth;
        }
    }

    int maxDepth_Iterative(Node* root) {
        int depth = 0;
        queue<Node*> q;
        if (root) {
            q.push(root);
        }
        for (; !q.empty(); ++depth) {
            size_t n = q.size();
            for (size_t i = 0; i < n; ++i) {
                root = q.front();
                q.pop();

                for (Node* child : root->children) {
                    q.push(child);

                }
            }
        }

        return depth;
    }

    int maxDepth(Node* root) {
        //return maxDepth_Recursive(root);
        return maxDepth_Iterative(root);
    }
};