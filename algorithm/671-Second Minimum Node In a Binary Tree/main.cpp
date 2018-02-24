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
    int findMinDifferentValue(TreeNode* root, int target) {
        if (!root) {
            return -1;
        }

        if (root->val != target) {
            return root->val;
        }
        else {
            int lftVal = findMinDifferentValue(root->left, target);
            int rhtVal = findMinDifferentValue(root->right, target);
            if (lftVal == -1) {
                return rhtVal;
            }
            if (rhtVal == -1) {
                return lftVal;
            }

            return min(lftVal, rhtVal);
        }
    }

    int findSecondMinimumValue(TreeNode* root) {
        return findMinDifferentValue(root, root->val);
    }

};