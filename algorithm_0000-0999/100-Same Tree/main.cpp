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
    bool recursive(TreeNode* p, TreeNode* q) {
        if (p == q) {
            return true;
        }
        return
            p && q && p->val == q->val &&
            recursive(p->left, q->left) &&
            recursive(p->right, q->right);
    }

    bool iterative(TreeNode* p, TreeNode* q) {
        for (stack<pair<TreeNode*, TreeNode*>> stk({{p, q}}); !stk.empty();) {
            auto [p, q] = stk.top();
            stk.pop();

            if (p == q) {
                continue;
            }
            if (!p || !q || p->val != q->val) {
                return false;
            }

            stk.emplace(p->left, q->left);
            stk.emplace(p->right, q->right);
        }

        return true;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        //return recursive(p, q);
        return iterative(p, q);
    }
};
