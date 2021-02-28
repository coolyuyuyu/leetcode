/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTreeHelper(nums.begin(), nums.end());
    }

    TreeNode* constructMaximumBinaryTreeHelper(vector<int>::const_iterator iterBgn, vector<int>::const_iterator iterEnd) {
        if (iterBgn == iterEnd) {
            return NULL;
        }

        vector<int>::const_iterator iterMax = max_element(iterBgn, iterEnd);
        TreeNode* root = new TreeNode(*iterMax);
        root->left = constructMaximumBinaryTreeHelper(iterBgn, iterMax);
        root->right = constructMaximumBinaryTreeHelper(iterMax + 1,iterEnd);
        return root;
    }
};