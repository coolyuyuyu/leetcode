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
    int longestUnivaluePathHelper(TreeNode* root, int& maxLen) {
        if (!root) {
            return 0;
        }

        int lftPartial = longestUnivaluePathHelper(root->left, maxLen);
        if (lftPartial && root->val != root->left->val) {
            lftPartial = 0;
        }

        int rhtPartial = longestUnivaluePathHelper(root->right, maxLen);
        if (rhtPartial && root->val != root->right->val) {
            rhtPartial = 0;
        }

        maxLen = max(maxLen, lftPartial + 1 + rhtPartial);
        return max(lftPartial, rhtPartial) + 1;
    }

    int longestUnivaluePath(TreeNode* root) {
        int maxLen = 0;
        longestUnivaluePathHelper(root, maxLen);
        if (maxLen > 0) {
            --maxLen;
        }

        return maxLen;
    }
};