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
    TreeNode* lowestCommonAncestor_Recursive(TreeNode* root, TreeNode* p, TreeNode* q, int& count) {
        if (!root) {
            count = 0;
            return root;
        }

        int lftCount;
        TreeNode* lftLCA = lowestCommonAncestor_Recursive(root->left, p, q, lftCount);
        if (lftCount == 2) {
            count = 2;
            return lftLCA;
        }

        int rhtCount;
        TreeNode* rhtLCA = lowestCommonAncestor_Recursive(root->right, p, q, rhtCount);
        if (rhtCount == 2) {
            count = 2;
            return rhtLCA;
        }

        count = lftCount + rhtCount;
        count += (root == p ? 1 : 0);
        count += (root == q ? 1 : 0);
        return root;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int count;
        TreeNode* lca = lowestCommonAncestor_Recursive(root, p, q, count);
        return (count == 2 ? lca : nullptr);
    }
};