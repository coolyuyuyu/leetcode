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
    TreeNode* deleteNodeRecv(TreeNode* pRoot, int key) {
        if (!pRoot) {
            return nullptr;
        }

        if (key < pRoot->val) {
            pRoot->left = deleteNodeRecv(pRoot->left, key);
        }
        else if (pRoot->val < key) {
            pRoot->right = deleteNodeRecv(pRoot->right, key);
        }
        else {
            // leaf
            if (!pRoot->left && !pRoot->right) {
                delete pRoot;
                return nullptr;
            }

            // one child
            if (!pRoot->left || !pRoot->right) {
                TreeNode* ret = pRoot->left ? pRoot->left : pRoot->right;
                delete pRoot;
                return ret;
            }

            // two childs
            TreeNode* pTmp = pRoot->right;
            while (pTmp->left) {
                pTmp = pTmp->left;
            }
            pRoot->val = pTmp->val;
            pRoot->right = deleteNodeRecv(pRoot->right, pRoot->val);
        }

        return pRoot;
    }

    TreeNode* deleteNode(TreeNode* pRoot, int key) {
        return deleteNodeRecv(pRoot, key);
    }
};