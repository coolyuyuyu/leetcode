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

    TreeNode* deleteNodeIter(TreeNode* pRoot, int key) {
        TreeNode** ppNode = &pRoot;
        while (*ppNode) {
            int val = (*ppNode)->val;
            if (key < val) {
                ppNode = &((*ppNode)->left);
            }
            else if (key == val) {
                break;
            }
            else {
                ppNode = &((*ppNode)->right);
            }
        }

        if (*ppNode == nullptr) {
            return pRoot;
        }

        if ((*ppNode)->left && (*ppNode)->right) {
            TreeNode* pTmp = (*ppNode)->right;
            if (pTmp->left) {
                TreeNode* pParent = nullptr;
                while (pTmp->left) {
                    pParent = pTmp;
                    pTmp = pTmp->left;
                }
                pParent->left = pTmp->right;

                pTmp->left = (*ppNode)->left;
                pTmp->right = (*ppNode)->right;
            }
            else {
                pTmp->left = (*ppNode)->left;
            }

            TreeNode* pDel = *ppNode;
            *ppNode = pTmp;
            delete pDel;
        }
        else {
            TreeNode* pDel = *ppNode;
            *ppNode = (*ppNode)->left ? (*ppNode)->left : (*ppNode)->right;
            delete pDel;
        }

        return pRoot;
    }

    TreeNode* deleteNode(TreeNode* pRoot, int key) {
        //return deleteNodeRecv(pRoot, key);

        return deleteNodeIter(pRoot, key);
    }
};