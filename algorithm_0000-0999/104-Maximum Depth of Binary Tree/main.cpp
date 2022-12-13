/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int recursive(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return 1 + std::max(recursive(root->left), recursive(root->right));
    }

    int iterative(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }

        int d = 0;
        for (; !q.empty(); ++d) {
            for (size_t i = 0, n = q.size(); i < n; ++i) {
                root = q.front();
                q.pop();

                if (root->left) {
                    q.push(root->left);
                }
                if (root->right) {
                    q.push(root->right);
                }
            }
        }

        if (!root) {
            return 0;
        }

        return d;
    }

    int maxDepth(TreeNode* root) {
        //return recursive(root);
        return iterative(root);
    }
};
