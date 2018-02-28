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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        assert(inorder.size() == postorder.size());
        return buildTree(inorder, 0, postorder, 0, inorder.size());
    }

    TreeNode* buildTree(vector<int>& inorder, size_t inBgn, vector<int>& postorder, size_t postBgn, size_t len) {
        if (len == 0) {
            return NULL;
        }

        int val = postorder[postBgn + len - 1];
        size_t inIndex = inBgn;
        for (size_t inEnd = inBgn + len; inIndex < inEnd; ++inIndex) {
            if (inorder[inIndex] == val) {
                break;
            }
        }

        size_t lftLen = inIndex - inBgn;
        size_t rhtLen = len - lftLen - 1;

        TreeNode* root = new TreeNode(val);
        root->left = buildTree(inorder, inBgn, postorder, postBgn, lftLen);
        root->right = buildTree(inorder, inIndex + 1, postorder, postBgn + lftLen, rhtLen);

        return root;
    }
};