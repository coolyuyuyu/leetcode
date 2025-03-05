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
    int closestValue(TreeNode* root, double target) {
        int ret = root->val;
        while (root) {
            double newDiff = std::abs(root->val - target), oldDiff = std::abs(ret - target);
            if (newDiff < oldDiff || (newDiff == oldDiff && root->val < ret)) {
                ret = root->val;
            }

            if (root->val < target) {
                root = root->right;
            }
            else if (root->val == target) {
                break;
            }
            else {
                root = root->left;
            }
        }

        return ret;
    }
};
