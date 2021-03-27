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
    TreeNode* insertIntoBST_Recursive(TreeNode* root, int val) {
        if (!root) {
            return (new TreeNode(val));
        }

        if (val < root->val) {
            root->left = insertIntoBST_Recursive(root->left, val);
        }
        else {
            assert(root->val < val);
            root->right = insertIntoBST_Recursive(root->right, val);
        }
        return root;
    }

    TreeNode* insertIntoBST_Iterative(TreeNode* root, int val) {
        TreeNode** ppNode = &root;
        while (*ppNode) {
            if (val < (*ppNode)->val) {
                ppNode = &((*ppNode)->left);
            }
            else {
                assert((*ppNode)->val < val);
                ppNode = &((*ppNode)->right);
            }
        }
        *ppNode = new TreeNode(val);

        return root;
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //return insertIntoBST_Recursive(root, val);
        return insertIntoBST_Iterative(root, val);
    }
};