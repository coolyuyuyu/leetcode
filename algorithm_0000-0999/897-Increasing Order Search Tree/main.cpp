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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* newRoot = NULL;
        TreeNode** ppNode = &newRoot;
        stack<TreeNode*> nodes;
        while (root || !nodes.empty()) {
            if (root) {
                nodes.push(root);
                root = root->left;
            }
            else {
                root = nodes.top();
                nodes.pop();

                *ppNode = root;
                (*ppNode)->left = NULL;
                ppNode = &((*ppNode)->right);
                
                root = root->right;
            }
        }

        return newRoot;
    }
};