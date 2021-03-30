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
    TreeNode* insertIntoMaxTree_Recursive(TreeNode* root, int val) {
        if (!root || root->val < val ) {
            return new TreeNode(val, root, nullptr);
        }

        root->right = insertIntoMaxTree_Recursive(root->right, val);
        return root;
    }


    TreeNode* insertIntoMaxTree_Iterative(TreeNode* root, int val) {
        TreeNode** ppNode = &root;
        while (*ppNode && val < (*ppNode)->val) {
            ppNode = &((*ppNode)->right);
        }
        *ppNode = new TreeNode(val, *ppNode, nullptr);

        return root;
    }

    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        return insertIntoMaxTree_Recursive(root, val);
        //return insertIntoMaxTree_Iterative(root, val);
    }
};