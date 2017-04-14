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
    int getMinimumDifferenceHelper(TreeNode* root, int& minVal, int& maxVal) {
        assert(root);
        int lftMinDiff, rhtMinDiff = INT_MAX;
        int minDiff = INT_MAX;
        if (root->left) {
            int lftMinVal, lftMaxVal;
            lftMinDiff = getMinimumDifferenceHelper(root->left, lftMinVal, lftMaxVal);

            minVal = lftMinVal;
            minDiff = min(minDiff, lftMinDiff);
            minDiff = min(minDiff, root->val - lftMaxVal);
        }
        else {
            minVal = root->val;
        }

        if (root->right) {
            int rhtMinVal, rhtMaxVal;
            rhtMinDiff = getMinimumDifferenceHelper(root->right, rhtMinVal, rhtMaxVal);

            maxVal = rhtMaxVal;
            minDiff = min(minDiff, rhtMinDiff);
            minDiff = min(minDiff, rhtMinVal - root->val);
        }
        else {
            maxVal = root->val;
        }

        return minDiff;
    }
    
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
        if (root) {
            int dummy;
            minDiff = getMinimumDifferenceHelper(root, dummy, dummy);
        }
        return minDiff;
    }
};