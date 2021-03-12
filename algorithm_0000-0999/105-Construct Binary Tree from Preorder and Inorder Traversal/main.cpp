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
    TreeNode* buildTree_Recursive(vector<int>& preorder, size_t preBgn, vector<int>& inorder, size_t inBgn, size_t size, map<int, size_t>& m) {
        if (size == 0) {
            return nullptr;
        }

        int val = preorder[preBgn];
        size_t lftSize = m[val] - inBgn;
        size_t rhtSize = size - lftSize - 1;

        TreeNode* root = new TreeNode(val);
        root->left = buildTree_Recursive(preorder, preBgn + 1, inorder, inBgn, lftSize, m);
        root->right = buildTree_Recursive(preorder, preBgn + 1 + lftSize, inorder, inBgn + lftSize + 1, rhtSize, m);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, size_t> m;
        for (size_t i = 0; i < inorder.size(); ++i) {
            m[inorder[i]] = i;
        }
        return buildTree_Recursive(preorder, 0, inorder, 0, preorder.size(), m);
    }
};