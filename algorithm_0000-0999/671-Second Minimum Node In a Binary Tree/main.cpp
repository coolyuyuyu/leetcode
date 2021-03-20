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
    // find next greater
    int findSecondMinimumValue_Recursive(TreeNode* root, int val) {
        if (!root) {
            return -1;
        }

        if (root->val == val) {
            int lftVal = findSecondMinimumValue_Recursive(root->left, val);
            int rhtVal = findSecondMinimumValue_Recursive(root->right, val);
            if (lftVal != -1 && rhtVal != -1) {
                return min(lftVal, rhtVal);
            }
            else {
                return (lftVal == -1 ? rhtVal : lftVal);
            }
        }
        else {
            return root->val;
        }
    }

    // find next greater
    int findSecondMinimumValue_Iterative(TreeNode* root, int val) {
        int* pRet = nullptr;

        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (val < node->val) {
                if (pRet) {
                    if (node->val < *pRet) {
                        pRet = &(node->val);
                    }
                }
                else {
                    pRet = &(node->val);
                }
            }

            if (node->val == val) {
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }

        return (pRet ? *pRet : -1);
    }

    int findSecondMinimumValue(TreeNode* root) {
        //return findSecondMinimumValue_Recursive(root, root->val);
        return findSecondMinimumValue_Iterative(root, root->val);
    }
};