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
    int rangeSumBST_Recursive(TreeNode* root, int low, int high) {
        assert(low <= high);
        if (!root) {
            return 0;
        }

        if (low <= root->val && root->val <= high) {
            return rangeSumBST_Recursive(root->left, low, root->val) + root->val + rangeSumBST_Recursive(root->right, root->val, high);
        }
        else if (high < root->val) {
            return rangeSumBST_Recursive(root->left, low, high);
        }
        else {
            assert(root->val < low);
            return rangeSumBST_Recursive(root->right, low, high);
        }
    }

    int rangeSumBST_Iterative(TreeNode* root, int low, int high) {
        stack<TreeNode*> stk({root});

        int sum = 0;
        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();

            if (low <= node->val && node->val <= high) {
                sum += node->val;
            }

            if (node->right && !(high < node->val)) {
                stk.push(node->right);
            }
            if (node->left && !(node->val < low)) {
                stk.push(node->left);
            }
        }

        return sum;
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        assert(root && (low <= high));

        //return rangeSumBST_Recursive(root, low, high);
        return rangeSumBST_Iterative(root, low, high);
    }
};