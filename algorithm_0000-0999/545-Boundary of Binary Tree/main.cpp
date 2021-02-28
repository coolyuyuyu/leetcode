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
    void boundaryOfBinaryTree(TreeNode* root, bool lftBound, bool rhtBound, vector<int>& boundries) {
        if (!root) {
            return;
        }

        if (lftBound) {
            boundries.emplace_back(root->val);
        }

        if (!lftBound && !rhtBound && !root->left && !root->right) {
            boundries.emplace_back(root->val);
        }

        boundaryOfBinaryTree(root->left, lftBound, rhtBound && !root->right, boundries);
        boundaryOfBinaryTree(root->right, lftBound && !root->left, rhtBound, boundries);

        if (rhtBound) {
            boundries.emplace_back(root->val);
        }
    }

    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root) {
            return {};
        }

        vector<int> boundries = {root->val};
        boundaryOfBinaryTree(root->left, true, false, boundries);
        boundaryOfBinaryTree(root->right, false, true, boundries);
        return boundries;
    }
};