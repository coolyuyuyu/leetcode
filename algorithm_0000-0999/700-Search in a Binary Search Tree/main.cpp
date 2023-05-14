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
    TreeNode* recursive(TreeNode* root, int val) {
        if (!root || root->val == val) {
            return root;
        }
        else if (root->val < val) {
            return recursive(root->right, val);
        }
        else {
            return recursive(root->left, val);
        }
    }

    TreeNode* iterative(TreeNode* root, int val) {
        while (root && root->val != val) {
            if (root->val < val) {
                root = root->right;
            }
            else {
                root = root->left;
            }
        }

        return root;
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        //return recursive(root, val);
        return iterative(root, val);
    }
};
