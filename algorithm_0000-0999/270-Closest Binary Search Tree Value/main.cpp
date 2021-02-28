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
    int closestValue(TreeNode* root, double target) {
        assert(root);

        double minAbsDiff = numeric_limits<double>::max();
        TreeNode* closetNode = root;
        while (root) {
            double diff = target - root->val;
            double absDiff = fabs(diff);
            if (absDiff < minAbsDiff) {
                minAbsDiff = absDiff;
                closetNode = root;
            }
            if (diff > 0) {
                root = root->right;
            }
            else {
                root = root->left;
            }

        }

        return closetNode->val;

    }
};