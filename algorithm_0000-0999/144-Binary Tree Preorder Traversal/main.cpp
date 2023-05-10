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
    void recursive(TreeNode* root, vector<int>& nums) {
        if (!root) {
            return;
        }

        nums.push_back(root->val);
        recursive(root->left, nums);
        recursive(root->right, nums);
    }

    vector<int> recursive(TreeNode* root) {
        vector<int> nums;
        recursive(root, nums);
        return nums;
    }

    vector<int> iterative(TreeNode* root) {
        vector<int> nums;
        for (stack<TreeNode*> stk({root}); !stk.empty();) {
            root = stk.top();
            stk.pop();

            if (!root) {
                continue;
            }

            nums.push_back(root->val);
            stk.push(root->right);
            stk.push(root->left);
        }

        return nums;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        //return recursive(root);
        return iterative(root);
    }
};
