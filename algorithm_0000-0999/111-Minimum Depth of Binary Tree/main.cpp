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
    int minDepth_Recursive(TreeNode* root, int depth = 0) {
        if (root) {
            if (root->left && root->right) {
                return min(minDepth_Recursive(root->left, depth + 1), minDepth_Recursive(root->right, depth + 1));
            }
            else if (root->left && !root->right) {
                return minDepth_Recursive(root->left, depth + 1);
            }
            else if (!root->left && root->right) {
                return minDepth_Recursive(root->right, depth + 1);
            }
            else {
                assert(!root->left && !root->right);
                return depth + 1;
            }
        }
        else {
            return depth;
        }
    }

    int minDepth_Iterative(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }
        for (int depth = 1; !q.empty(); ++depth) {
            size_t n = q.size();
            for (size_t i = 0; i < n; ++i) {
                root = q.front();
                q.pop();

                if (!root->left && !root->right) {
                    return depth;
                }

                if (root->left) {
                    q.push(root->left);
                }
                if (root->right) {
                    q.push(root->right);
                }
            }
        }

        return 0;
    }

    int minDepth(TreeNode* root) {
        //return minDepth_Recursive(root);
        return minDepth_Iterative(root);
    }
};