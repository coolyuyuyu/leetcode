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
    TreeNode* recursive(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val < root->val && q->val < root->val) {
            return recursive(root->left, p, q);
        }
        else if (root->val < p->val && root->val < q->val) {
            return recursive(root->right, p, q);
        }
        else {
            return root;
        }
    }

    TreeNode* iterative(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (std::max(p->val, q->val) < root->val || root->val < std::min(p->val, q->val)) {
            if (p->val < root->val) {
                root = root->left;
            }
            else {
                root = root->right;
            }
        }

        return root;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //return recursive(root, p, q);
        return iterative(root, p, q);
    }
};
