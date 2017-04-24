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
    int findTilt(TreeNode* root) {
        int sum = 0;
        int diff = 0;
        findTiltHelper(root, sum, diff);
        return diff;
    }

    void findTiltHelper(TreeNode* root, int& sum, int& diff) {
        if (!root) {
            sum = 0;
            return;
        }

        int lftSum = 0;
        findTiltHelper(root->left, lftSum, diff);

        int rhtSum = 0;
        findTiltHelper(root->right, rhtSum, diff);

        sum = lftSum + rhtSum + root->val;

        diff += abs(lftSum - rhtSum);
    }
};