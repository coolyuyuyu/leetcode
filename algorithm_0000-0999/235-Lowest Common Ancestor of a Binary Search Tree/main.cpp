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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int valP = p->val, valQ = q->val;
        while (root) {
            int val = root->val;
            if (val < valP && val < valQ) {
                root = root->right;
            }
            else if (valP < val && valQ < val) {
                root = root->left;
            }
            else {
                break;
            }
        }

        return root;
    }
};