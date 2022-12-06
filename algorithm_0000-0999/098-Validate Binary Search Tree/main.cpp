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
    bool isValidBST_Recursive(TreeNode* root, TreeNode*& prev) {
        if (!root) {
            return true;
        }

        if (!isValidBST_Recursive(root->left, prev)) {
            return false;
        }


        if (prev && root->val <= prev->val) {
            return false;
        }
        prev = root;

        return isValidBST_Recursive(root->right, prev);
    }

    bool isValidBST_Recursive(TreeNode* root) {
        TreeNode* prev = nullptr;
        return isValidBST_Recursive(root, prev);
    }

    bool isValidBST_Iterative(TreeNode* root) {
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

    bool isValidBST(TreeNode* root) {
        //return isValidBST_Recursive(root);
        return isValidBST_Iterative(root);
    }
};
