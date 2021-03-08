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
    bool isSameTree_Recursive(TreeNode* p, TreeNode* q) {
        if (p == q) {
            return true;
        }
        else {
            return (p && q && p->val == q->val) && isSameTree_Recursive(p->left, q->left) && isSameTree_Recursive(p->right, q->right);
        }
    }

    bool isSameTree_Iterative(TreeNode* p, TreeNode* q) {
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

            if (p != q) {
                if (p->val != q->val) {
                    return false;
                }
                if ((p->right && !q->right) || (!p->right && q->right)) {
                    return false;
                }
                if ((p->left && !q->left) || (!p->left && q->left)) {
                    return false;
                }
            }

            assert(p->right && q->right || (!p->right && !q->right));
            if (p->right) {
                stk.emplace(p->right, q->right);
            }

            assert(p->left && q->left || (!p->left && !q->left));
            if (p->left) {
                stk.emplace(p->left, q->left);
            }
        }

        return true;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        //return isSameTree_Recursive(p, q);
        return isSameTree_Iterative(p, q);
    }
};