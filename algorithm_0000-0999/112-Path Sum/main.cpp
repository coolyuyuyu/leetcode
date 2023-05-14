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
    bool recursive(TreeNode* root, int targetSum) {
        std::function<bool(TreeNode*, int)> f = [&](TreeNode* root, int targetSum) {
            if(!root) {
                return false;
            }

            if (!root->left && !root->right) {
                return (root->val == targetSum);
            }
            else {
                targetSum -= root->val;
                return f(root->left, targetSum) || f(root->right, targetSum);
            }
        };
        return f(root, targetSum);
    }

    bool iterative(TreeNode* root, int targetSum) {
        for (stack<pair<TreeNode*, int>> stk({{root, targetSum}}); !stk.empty();) {
            auto [root, targetSum] = stk.top();
            stk.pop();

            if (!root) {
                continue;
            }

            if (!root->left && !root->right && root->val == targetSum) {
                return true;
            }

            targetSum -= root->val;
            stk.emplace(root->left, targetSum);
            stk.emplace(root->right, targetSum);
        }

        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return recursive(root, targetSum);
        //return iterative(root, targetSum);
    }
};
