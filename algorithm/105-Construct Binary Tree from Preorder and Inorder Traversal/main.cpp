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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        assert(preorder.size() == inorder.size());
        return buildTree(preorder, 0, inorder, 0, preorder.size());
    }

    TreeNode* buildTree(vector<int>& preorder, size_t preBgn, vector<int>& inorder, size_t inBgn, size_t len) {
        if (len == 0) {
            return NULL;
        }

        int val = preorder[preBgn];
        size_t inIndex = inBgn;
        for (size_t inEnd = inBgn + len; inIndex < inEnd; ++inIndex) {
            if (inorder[inIndex] == val) {
                break;
            }
        }

        size_t lftLen = inIndex - inBgn;
        size_t rhtLen = len - lftLen - 1;

        TreeNode* root = new TreeNode(val);
        root->left = buildTree(preorder, preBgn + 1, inorder, inBgn, lftLen);
        root->right = buildTree(preorder, preBgn + 1 + lftLen, inorder, inIndex + 1, rhtLen);

        return root;
    }
};