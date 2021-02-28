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
    int rangeSumBSTIter(TreeNode* root, int L, int R) {
        int sum = 0;

        TreeNode* cur = root;
        stack<TreeNode*> stk;
        while (cur || !stk.empty()) {
            if (cur) {
                stk.push(cur);
                if (cur->val <= L) {
                    cur = NULL;
                }
                else {
                    cur = cur->left;
                }
            }
            else {
                cur = stk.top();
                stk.pop();

                if (L <= cur->val && cur->val <= R) {
                    sum += cur->val;
                }


                if (R <= cur->val) {
                    cur = NULL;
                }
                else {
                    cur = cur->right;
                }
            }

        }
        return sum;
    }

    int rangeSumBSTRecv(TreeNode* root, int L, int R) {
        if (!root) {
            return 0;
        }

        if (root->val < L) {
            return rangeSumBSTRecv(root->right, L, R);
        }
        else if (R < root->val) {
            return rangeSumBSTRecv(root->left, L, R);
        }
        else {
            assert(L <= root->val && root->val <= R);
            return rangeSumBSTRecv(root->left, L, R) + root->val + rangeSumBSTRecv(root->right, L, R);
        }
    }


    int rangeSumBST(TreeNode* root, int L, int R) {
        return rangeSumBSTIter(root, L, R);

        //return rangeSumBSTRecv(root, L, R);
    }
};