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
    int longestUnivaluePathHelper(TreeNode* root, int& maxNumOfNodes) {
        if (!root) {
            return 0;
        }

        int lftPartial = longestUnivaluePathHelper(root->left, maxNumOfNodes);
        if (lftPartial && root->val != root->left->val) {
            lftPartial = 0;
        }

        int rhtPartial = longestUnivaluePathHelper(root->right, maxNumOfNodes);
        if (rhtPartial && root->val != root->right->val) {
            rhtPartial = 0;
        }

        maxNumOfNodes = max(maxNumOfNodes, lftPartial + 1 + rhtPartial);
        return max(lftPartial, rhtPartial) + 1;
    }

    int longestUnivaluePath(TreeNode* root) {
        int maxNumOfNodes = 0;
        longestUnivaluePathHelper(root, maxNumOfNodes);
        return maxNumOfNodes > 0 ? maxNumOfNodes - 1 : 0;
    }
};