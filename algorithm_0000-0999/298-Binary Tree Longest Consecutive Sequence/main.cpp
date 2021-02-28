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
    int longestConsecutiveDfs(TreeNode* root, int& maxLcs) {
        if (!root) {
            return 0;
        }

        int lcsLft = longestConsecutiveDfs(root->left, maxLcs);
        int lcsRht = longestConsecutiveDfs(root->right, maxLcs);

        int lcs = 1;
        if (root->left && root->val + 1 == root->left->val) {
            lcs = max(lcs, lcsLft + 1);
        }
        if (root->right && (root->val + 1 == root->right->val)) {
            lcs = max(lcs, lcsRht + 1);
        }

        maxLcs = max(maxLcs, lcs);
        return lcs;
    }

    int longestConsecutive(TreeNode* root) {
        int maxLcs = 0;
        longestConsecutiveDfs(root, maxLcs);
        return maxLcs;
    }
};