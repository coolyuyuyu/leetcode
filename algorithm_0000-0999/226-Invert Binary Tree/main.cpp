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
    TreeNode* invertTree(TreeNode* root) {
        return invertTreeIter(root);
    }

    TreeNode* invertTreeIter(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }

        while (!q.empty()) {
            TreeNode* pNode = q.front();
            q.pop();

            TreeNode* pLft = pNode->left;
            pNode->left = pNode->right;
            pNode->right = pLft;
            if (pNode->left) {
                q.push(pNode->left);
            }
            if (pNode->right) {
                q.push(pNode->right);
            }
        }

        return root;
    }
    
    TreeNode* invertTreeRecv(TreeNode* root) {
        if (root) {
            TreeNode* pLft = root->left;
            root->left = invertTree(root->right);
            root->right = invertTree(pLft);
        }

        return root;
    }
};