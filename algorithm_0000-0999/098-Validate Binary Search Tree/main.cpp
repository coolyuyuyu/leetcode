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
    bool isValidBST_Recursive(TreeNode* root, int minVal = numeric_limits<int>::min(), int maxVal = numeric_limits<int>::max()) {
        if (!root) {
            return true;
        }

        if (minVal <= root->val && root->val <= maxVal) {
            if (root->left) {
                if (root->val == numeric_limits<int>::min() || !isValidBST_Recursive(root->left, minVal, root->val - 1)) {
                    return false;
                }
            }

            if (root->right) {
                if (root->val == numeric_limits<int>::max() || !isValidBST_Recursive(root->right, root->val + 1, maxVal)) {
                    return false;
                }
            }

            return true;
        }
        else {
            return false;
        }
    }

    bool isValidBST_Iterative(TreeNode* root) {
        int* pPreVal = nullptr;
        stack<pair<TreeNode*, bool>> stk;
        if (root) {
            stk.emplace(root, false);
        }
        while (!stk.empty()) {
            TreeNode* node = stk.top().first;
            bool visited = stk.top().second;
            stk.pop();

            if (visited) {
                if (pPreVal && node->val <= *pPreVal) {
                    return false;
                }
                pPreVal = &(node->val);
            }
            else {
                if (node->right) {
                    stk.emplace(node->right, false);
                }
                stk.emplace(node, true);
                if (node->left) {
                    stk.emplace(node->left, false);
                }
            }
        }

        return true;
    }

    bool isValidBST(TreeNode* root) {
        return isValidBST_Recursive(root);
        //return isValidBST_Iterative(root);
    }
};