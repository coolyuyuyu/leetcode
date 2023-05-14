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
        if (!root) {
            root = new TreeNode(val);
        }
        else if (root->val < val) {
            root->right = recursive(root->right, val);;
        }
        else {
            root->left = recursive(root->left, val);
        }

        return root;
    }

    TreeNode* iterative(TreeNode* root, int val) {
        TreeNode** ppCur = &root;
        while (*ppCur) {
            if ((*ppCur)->val < val) {
                ppCur = &((*ppCur)->right);
            }
            else {
                ppCur = &((*ppCur)->left);
            }
        }
        *ppCur = new TreeNode(val);

        return root;
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //return recursive(root, val);
        return iterative(root, val);
    }
};
