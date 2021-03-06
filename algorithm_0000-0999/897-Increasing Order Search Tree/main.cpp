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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* pHeadNew = nullptr;
        TreeNode** ppHeadNew = &pHeadNew;

        stack<TreeNode*> stk;
        while (root || !stk.empty()) {
            if (root) {
                stk.push(root);
                root = root->left;
            }
            else {
                root = stk.top();
                stk.pop();

                *ppHeadNew = root;
                (*ppHeadNew)->left = nullptr;
                ppHeadNew = &((*ppHeadNew)->right);

                root = root->right;
            }
        }
        assert(!(*ppHeadNew));

        return pHeadNew;
    }
};