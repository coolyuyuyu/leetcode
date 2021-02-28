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
    pair<size_t, size_t> longestConsecutive2(TreeNode* root, size_t& maxLen) {
        if (!root) {
            return {0 ,0};
        }

        pair<size_t, size_t> pairLft = longestConsecutive2(root->left, maxLen);
        pair<size_t, size_t> pairRht = longestConsecutive2(root->right, maxLen);

        size_t inc = 1;
        if (root->left && root->val + 1 == root->left->val) {
            inc = 1 + pairLft.first;
        }
        if (root->right && root->val + 1 == root->right->val) {
            inc = max(inc, 1 + pairRht.first);
        }

        size_t dec = 1;
        if (root->left && root->val - 1 == root->left->val) {
            dec = 1 + pairLft.second;
        }
        if (root->right && root->val - 1 == root->right->val) {
            dec = max(dec, 1 + pairRht.second);
        }

        maxLen = max(maxLen, max(inc, dec));

        if (root->left && root->right && root->val + 1 == root->left->val && root->val - 1 == root->right->val) {
            maxLen = max(maxLen, pairLft.first + 1 + pairRht.second);
        }
        if (root->left && root->right && root->val - 1 == root->left->val && root->val + 1 == root->right->val) {
            maxLen = max(maxLen, pairLft.second + 1 + pairRht.first);
        }

        return {inc, dec};
    }

    pair<size_t, size_t> longestConsecutive(TreeNode* root, size_t& maxLen) {
        if (!root) {
            return {0 ,0};
        }

        pair<size_t, size_t> pairLft = longestConsecutive(root->left, maxLen);
        pair<size_t, size_t> pairRht = longestConsecutive(root->right, maxLen);
        size_t inc = 1, dec = 1;
        if (root->left) {
            if (root->val + 1 == root->left->val) {
                inc = max(inc, 1 + pairLft.first);
            }
            if (root->val - 1 == root->left->val) {
                dec = max(dec, 1 + pairLft.second);
            }
        }
        if (root->right) {
            if (root->val + 1 == root->right->val) {
                inc = max(inc, 1 + pairRht.first);
            }
            if (root->val - 1 == root->right->val) {
                dec = max(dec, 1 + pairRht.second);
            }
        }
        maxLen = max(maxLen, max(inc + dec - 1, max(inc, dec)));

        return {inc, dec};
    }

    size_t longestConsecutive(TreeNode* root) {
        size_t maxLen = 0;
        longestConsecutive(root, maxLen);
        return maxLen;
    }
};