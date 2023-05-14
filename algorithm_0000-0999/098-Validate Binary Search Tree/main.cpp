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
    bool inorder_recursive(TreeNode* root) {
        TreeNode* prev = nullptr;
        std::function<bool(TreeNode*)> f = [&](TreeNode* root) {
            if (!root) {
                return true;
            }

            if  (!f(root->left)) {
                return false;
            }
            if (prev && root->val <= prev->val) {
                return false;
            }
            prev = root;

            return f(root->right);

        };
        return f(root);
    }

    bool inorder_iterative(TreeNode* root) {
        TreeNode* prev = nullptr;
        for (stack<pair<TreeNode*, bool>> stk({{root, false}}); !stk.empty();) {
            auto [root, visited] = stk.top();
            stk.pop();

            if (!root) {
                continue;
            }

            if (visited) {
                if (prev && root->val <= prev->val) {
                    return false;
                }
                prev = root;
            }
            else {
                stk.emplace(root->right, false);
                stk.emplace(root, true);
                stk.emplace(root->left, false);
            }
        }

        return true;
    }

    bool converge_recursive(TreeNode* root, int lo = INT_MIN, int hi = INT_MAX) {
        if (!root) {
            return true;
        }

        if (root->val < lo || hi < root->val) {
            return false;
        }
        if (root->left && (root->val == INT_MIN || !converge_recursive(root->left, lo, root->val - 1))) {
            return false;
        }
        if (root->right && (root->val == INT_MAX || !converge_recursive(root->right, root->val + 1, hi))) {
            return false;
        }

        return true;
    }

    bool converge_iterative(TreeNode* root, int lo = INT_MIN, int hi = INT_MAX) {
        for (stack<tuple<TreeNode*, int, int>> stk({{root, INT_MIN, INT_MAX}}); !stk.empty();) {
            auto [root, lo, hi] = stk.top();
            stk.pop();

            if (!root) {
                continue;
            }

            if (root->val < lo || hi < root->val) {
                return false;
            }
            if (root->left) {
                if (root->val == INT_MIN) {
                    return false;
                }
                stk.emplace(root->left, lo, root->val - 1);
            }
            if (root->right) {
                if (root->val == INT_MAX) {
                    return false;
                }
                stk.emplace(root->right, root->val + 1, hi);
            }
        }

        return true;
    }

    bool isValidBST(TreeNode* root) {
        //return inorder_recursive(root);
        //return inorder_iterative(root);
        //return converge_recursive(root);
        return converge_iterative(root);
    }
};
