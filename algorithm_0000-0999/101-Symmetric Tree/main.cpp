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
    bool isSymmetric_Recursive(TreeNode* root) {
        std::function<bool(TreeNode*, TreeNode*)> compare = [&compare](TreeNode* p, TreeNode* q) -> bool {
            if ((p && !q) || (!p && q)) {
                return false;
            }

            return (!p && !q) || ((p->val == q->val) && compare(p->left, q->right) && compare(p->right, q->left));
        };

        return !root || compare(root->left, root->right);
    }

    bool isSymmetric_Iterative(TreeNode* root) {
        assert(root);
        TreeNode *p = root->left, *q = root->right;
        if ((p && !q) || (!p && q)) {
            return false;
        }
        assert((p && q) || (!p && !q));

        stack<pair<TreeNode*, TreeNode*>> stk;
        if (p) {
            stk.emplace(p, q);
        }
        while (!stk.empty()) {
            p = stk.top().first;
            q = stk.top().second;
            stk.pop();

            if (p->val != q->val) {
                return false;
            }
            if ((p->left && !q->right) || (!p->left && q->right)) {
                return false;
            }
            if ((p->right && !q->left) || (!p->right && q->left)) {
                return false;
            }

            assert(p->left && q->right || (!p->left && !q->right));
            if (p->left) {
                stk.emplace(p->left, q->right);
            }

            assert(p->right && q->left || (!p->right && !q->left));
            if (p->right) {
                stk.emplace(p->right, q->left);
            }
        }

        return true;
    }

    bool isSymmetric(TreeNode* root) {
        //return isSymmetric_Recursive(root);
        return isSymmetric_Iterative(root);
    }
};