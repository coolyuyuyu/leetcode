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
    bool isMirror(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }
        if ((p && !q) || (!p && q) || p->val != q->val) {
            return false;
        }

        return isMirror(p->left, q->right) && isMirror(p->right, q->left);
    }

    bool isSymmetric_recursive(TreeNode* root) {
        return isMirror(root, root);
    }

    bool isSymmetric_iterative(TreeNode* root) {
        stack<pair<TreeNode*, TreeNode*>> stk({{root, root}});
        while (!stk.empty()) {
            auto [p, q] = stk.top();
            stk.pop();

            if (!p && !q) {
                continue;
            }
            if ((p && !q) || (!p && q) || p->val != q->val) {
                return false;
            }

            stk.emplace(p->left, q->right);
            stk.emplace(p->right, q->left);
        }

        return true;
    }

    bool isSymmetric(TreeNode* root) {
        //return isSymmetric_recursive(root);
        return isSymmetric_iterative(root);
    }
};
