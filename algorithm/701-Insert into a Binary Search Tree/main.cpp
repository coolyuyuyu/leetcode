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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode** ppCur = &root;
        while (*ppCur) {
            assert((*ppCur)->val != val);
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
};