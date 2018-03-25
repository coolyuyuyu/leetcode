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
    pair<int, int> robHelper(TreeNode* root) {
        if (!root) {
            return {0,0};
        }

        pair<int, int> vPairLft = robHelper(root->left);
        pair<int, int> vPairRht = robHelper(root->right);

        int noRobbed = max(vPairLft.first, vPairLft.second) + max(vPairRht.first, vPairRht.second);
        int robbed = root->val + vPairLft.first + vPairRht.first;
        return {noRobbed, robbed};
    }

    int rob(TreeNode* root) {
         //first:not robed, second:robbed
        pair<int, int> vPair = robHelper(root);
        return max(vPair.first, vPair.second);
    }
};