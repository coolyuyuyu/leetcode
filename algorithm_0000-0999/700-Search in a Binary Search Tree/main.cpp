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
    TreeNode* searchBST_Recursive(TreeNode* root, int val) {
        if (!root || root->val == val) {
            return root;
        }
        else if (val < root->val) {
            return searchBST_Recursive(root->left, val);
        }
        else {
            return searchBST_Recursive(root->right, val);
        }
    }

    TreeNode* searchBST_Iterative(TreeNode* root, int val) {
        while (root && root->val != val) {
            if (val < root->val) {
                root = root->left;
            }
            else {
                root = root->right;
            }
        }

        return root;
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        //return searchBST_Recursive(root, val);

        return searchBST_Iterative(root, val);
    }
};