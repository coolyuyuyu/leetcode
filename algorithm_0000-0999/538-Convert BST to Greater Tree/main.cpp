/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        travelBSTHelper(root, sum);
        return root;
    }

    void travelBSTHelper(TreeNode* root, int& sum) {
        if (root) {
            travelBSTHelper(root->right, sum);
            root->val += sum;
            sum = root->val;
            travelBSTHelper(root->left, sum);
        }
    }
};