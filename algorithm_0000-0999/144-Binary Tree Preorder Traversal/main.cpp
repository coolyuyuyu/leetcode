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
        
        stack<TreeNode*> stk;
        if (root) {
            stk.push(root);
        }
        while (!stk.empty()) {
            root = stk.top();
            stk.pop();

            nums.push_back(root->val);

            if (root->right) {
                stk.push(root->right);
            }
            if (root->left) {
                stk.push(root->left);
            }
        }

        return nums;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        //return recursive(root);
        return iterative(root);
    }
};
