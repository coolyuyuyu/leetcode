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
    int distributeCoins(TreeNode* root, int& count) {
        if (!root) {
            return 0;
        }

        int lft = distributeCoins(root->left, count), rht = distributeCoins(root->right, count);
        count += (abs(lft) + abs(rht));

        return (root->val + lft + rht - 1);
    }

    int distributeCoins(TreeNode* root) {
        int count = 0;
        distributeCoins(root, count);
        return count;
    }
};