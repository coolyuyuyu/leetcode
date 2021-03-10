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
    bool isIdentical_Recursive(TreeNode* s, TreeNode* t) {
        return (s == t) || (s && t && s->val == t->val && isIdentical_Recursive(s->left, t->left) && isIdentical_Recursive(s->right, t->right));
    };

    bool isSubtree_Recursive(TreeNode* s, TreeNode* t) {
        if (isIdentical_Recursive(s, t)) {
            return true;
        }
        else {
            if (s) {
                return (isSubtree_Recursive(s->left, t) || isSubtree_Recursive(s->right, t));
            }
            else {
                assert(!s && t);
                return false;
            }
        }
    }

    bool isIdentical_Iterative(TreeNode* s, TreeNode* t) {
        queue<pair<TreeNode*, TreeNode*>> q({{s, t}});
        while (!q.empty()) {
            s = q.front().first;
            t = q.front().second;
            q.pop();

            if (s != t) {
                if (s && t) {
                    if (s->val != t->val) {
                        return false;
                    }
                    q.emplace(s->left, t->left);
                    q.emplace(s->right, t->right);
                }
                else if ((s && !t) || (!s && t)) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isSubtree_Iterative(TreeNode* s, TreeNode* t) {
        if (isIdentical_Iterative(s, t)) {
            return true;
        }

        stack<TreeNode*> stk;
        if (s) {
            stk.push(s);
        }
        while (!stk.empty()) {
            s = stk.top();
            stk.pop();

            if (isIdentical_Iterative(s, t)) {
                return true;
            }

            if (s->right) {
                stk.push(s->right);
            }
            if (s->left) {
                stk.push(s->left);
            }
        }

        return false;
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        //return isSubtree_Recursive(s, t);
        return isSubtree_Iterative(s, t);
    }
};
