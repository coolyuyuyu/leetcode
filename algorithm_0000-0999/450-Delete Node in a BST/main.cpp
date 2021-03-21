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
    TreeNode* deleteNode_Recursive(TreeNode* root, int key) {
        if (!root) {
            return nullptr;
        }

        if (key < root->val) {
            root->left = deleteNode_Recursive(root->left, key);
        }
        else if (key == root->val) {
            if (!root->left || !root->right) {
                TreeNode* del = root;
                root = (root->left ? root->left : root->right);
                delete del;
            }
            else {
                TreeNode* tmp = root->right;
                while (tmp->left) {
                    tmp = tmp->left;
                }
                root->val = tmp->val;
                root->right = deleteNode_Recursive(root->right, root->val);
            }
        }
        else {
            root->right = deleteNode_Recursive(root->right, key);
        }

        return root;
    }

    TreeNode* deleteNode_Iterative(TreeNode* root, int key) {
        TreeNode** ppNode = &root;
        while (*ppNode) {
            if (key < (*ppNode)->val) {
                ppNode = &((*ppNode)->left);
            }
            else if (key == (*ppNode)->val) {
                break;
            }
            else {
                ppNode = &((*ppNode)->right);
            }
        }

        if (*ppNode) {
            TreeNode* del = *ppNode;
            if (!((*ppNode)->left) || !((*ppNode)->right)) {
                *ppNode = ((*ppNode)->left ? (*ppNode)->left : (*ppNode)->right);
            }
            else {
                TreeNode* tmp = (*ppNode)->right;
                if (tmp->left) {
                    TreeNode* parent;
                    while (tmp->left) {
                        parent = tmp;
                        tmp = tmp->left;
                    }
                    parent->left = tmp->right;

                    tmp->right = (*ppNode)->right;
                }
                tmp->left = (*ppNode)->left;
                *ppNode = tmp;
            }

            delete del;
        }

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        //return deleteNode_Recursive(root, key);
        return deleteNode_Iterative(root, key);
    }
};