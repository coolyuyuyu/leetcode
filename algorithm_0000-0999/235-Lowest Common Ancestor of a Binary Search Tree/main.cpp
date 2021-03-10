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
    TreeNode* lowestCommonAncestor_Recursive(TreeNode* root, int p, int q) {
        assert(p < q);

        if (q < root->val) {
            return lowestCommonAncestor_Recursive(root->left, p, q);
        }
        else if (root->val < p) {
            return lowestCommonAncestor_Recursive(root->right, p, q);
        }
        else {
            return root;
        }
    }

    TreeNode* lowestCommonAncestor_Iterative(TreeNode* root, int p, int q) {
        assert(p < q);

        while (root) {
            if (q < root->val) {
                root = root->left;
            }
            else if (root->val < p) {
                root = root->right;
            }
            else {
                break;
            }
        }

        return root;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (q->val < p->val) {
            swap(p, q);
        }

        //return lowestCommonAncestor_Recursive(root, p->val, q->val);
        return lowestCommonAncestor_Iterative(root, p->val, q->val);
    }
};
