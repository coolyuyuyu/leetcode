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
    bool recursive(TreeNode* root1, TreeNode* root2) {
        std::function<bool(TreeNode*,TreeNode*)> f = [&](TreeNode* a, TreeNode* b) {
            if (!a && !b) {
                return true;
            }
            else if (!a && b || a && !b || a->val != b->val) {
                return false;
            }
            else {
                return (f(a->left, b->left) && f(a->right, b->right)) ||
                       (f(a->left, b->right) && f(a->right, b->left));
            }
        };

        return f(root1, root2);
    }

    bool iterative(TreeNode* root1, TreeNode* root2) {
        std::function<bool(TreeNode*, TreeNode*)> checkEqual = [](TreeNode* a, TreeNode* b) {
            return (!a && !b) || (a && b && a->val == b->val);
        };
        for (queue<pair<TreeNode*, TreeNode*>> q({{root1, root2}}); !q.empty(); ) {
            auto [a, b] = q.front();
            q.pop();

            if (!a && !b) {
                continue;
            }
            else if (!a && b || a && !b || a->val != b->val) {
                return false;
            }
            else if (checkEqual(a->left, b->left) && checkEqual(a->right, b->right)) {
                q.emplace(a->left, b->left);
                q.emplace(a->right, b->right);
            }
            else if (checkEqual(a->left, b->right) && checkEqual(a->right, b->left)) {
                q.emplace(a->left, b->right);
                q.emplace(a->right, b->left);
            }
            else {
                return false;
            }
        }

        return true;
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        //return recursive(root1, root2);
        return iterative(root1, root2);
    }
};
