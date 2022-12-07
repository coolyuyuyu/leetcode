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
    bool checkSorted_recursive(TreeNode* root, TreeNode*& prev) {
        if (!root) {
            return true;
        }

        if (!checkSorted_recursive(root->left, prev)) {
            return false;
        }
        if (prev && root->val <= prev->val) {
            return false;
        }
        prev = root;

        return checkSorted_recursive(root->right, prev);
    }

    // recursive sorted check
    bool checkSorted_recursive(TreeNode* root) {
        TreeNode* prev = nullptr;
        return checkSorted_recursive(root, prev);
    }

    bool checkSorted_iterative(TreeNode* root) {
        stack<pair<TreeNode*, bool>> stk;
        if (root) {
            stk.emplace(root, false);
        }
        for (TreeNode* pre = nullptr; !stk.empty();) {
            TreeNode* cur = stk.top().first;
            bool visited = stk.top().second;
            stk.pop();

            if (visited) {
                if (pre && cur->val <= pre->val) {
                    return false;
                }
                pre = cur;
            }
            else {
                if (cur->right) {
                    stk.emplace(cur->right, false);
                }
                stk.emplace(cur, true);
                if (cur->left) {
                    stk.emplace(cur->left, false);
                }
            }
        }

        return true;
    }

    // recursive convergence check
    bool checkConvergence_recursive(TreeNode* root, int lft = INT_MIN, int rht = INT_MAX) {
        if (!root) {
            return true;
        }

        if (root->val < lft || rht < root->val) {
            return false;
        }
        if (root->left && (root->val == INT_MIN || !checkConvergence_recursive(root->left, lft, root->val - 1))) {
            return false;
        }
        if (root->right && (root->val == INT_MAX || !checkConvergence_recursive(root->right, root->val + 1, rht))) {
            return false;
        }

        return true;
    }

    // iterative convergence check
    bool checkConvergence_iterative(TreeNode* root, int lft = INT_MIN, int rht = INT_MAX) {
        queue<tuple<TreeNode*, int, int>> q;
        if (root) {
            q.emplace(root, INT_MIN, INT_MAX);
        }

        while (!q.empty()) {
            root = std::get<0>(q.front());
            int lft = std::get<1>(q.front());
            int rht = std::get<2>(q.front());
            q.pop();

            if (root->val < lft || rht < root->val) {
                return false;
            }
            if (root->left) {
                if (root->val == INT_MIN) {
                    return false;
                }
                q.emplace(root->left, lft, root->val - 1);
            }
            if (root->right) {
                if (root->val == INT_MAX) {
                    return false;
                }
                q.emplace(root->right, root->val + 1, rht);
            }
        }

        return true;
    }

    bool isValidBST(TreeNode* root) {
        //return checkSorted_recursive(root);
        //return checkSorted_iterative(root);

        //return checkConvergence_recursive(root);
        return checkConvergence_iterative(root);
    }
};
