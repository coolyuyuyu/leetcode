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
    int maxDepth_Recursive(TreeNode* root, int depth = 0) {
        if(!root) {
            return depth;
        }
        else {
            return max(maxDepth_Recursive(root->left, depth + 1), maxDepth_Recursive(root->right, depth + 1));
        }
    }

    int maxDepth_Iterative(TreeNode* root) {
        int depth = 0;
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }
        for (; !q.empty(); ++depth) {
            size_t n = q.size();
            for (size_t i = 0; i < n; ++i) {
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

        return depth;
    }

    int maxDepth(TreeNode* root) {
        //return maxDepth_Recursive(root);
        return maxDepth_Iterative(root);
    }
};