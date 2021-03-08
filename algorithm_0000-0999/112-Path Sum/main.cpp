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
    bool hasPathSum_Recursive(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }

        targetSum -= root->val;
        if (!root->left && !root->right) {
            return targetSum == 0;
        }
        else {
            return (hasPathSum_Recursive(root->left, targetSum) || hasPathSum_Recursive(root->right, targetSum));
        }
    }

    bool hasPathSum_Iterative(TreeNode* root, int targetSum) {
        queue<pair<TreeNode*, int>> q;
        if (root) {
            q.emplace(root, targetSum);
        }
        while (!q.empty()) {
            size_t n = q.size();
            for (size_t i = 0; i < n; ++i) {
                root = q.front().first;
                targetSum = q.front().second - root->val;
                q.pop();

                if (!root->left && !root->right && targetSum == 0) {
                    return true;
                }

                if (root->left) {
                    q.emplace(root->left, targetSum);
                }
                if (root->right) {
                    q.emplace(root->right, targetSum);
                }
            }
        }

        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        //return hasPathSum_Recursive(root, targetSum);
        return hasPathSum_Iterative(root, targetSum);
    }
};