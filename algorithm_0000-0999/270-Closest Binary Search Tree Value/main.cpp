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
    int closestValue_Recursive(TreeNode* root, double target) {
        assert(root);

        int closestVal = root->val;
        double minDiff = abs(closestVal - target);
        if (target < root->val) {
            if (root->left) {
                int val = closestValue_Recursive(root->left, target);
                if (abs(val - target) < minDiff) {
                    closestVal = val;
                }
            }
        }
        else if (root->val < target) {
            if (root->right) {
                int val = closestValue_Recursive(root->right, target);
                if (abs(val - target) < minDiff) {
                    closestVal = val;
                }
            }
        }

        return closestVal;
    }

    int closestValue_Iterative(TreeNode* root, double target) {
        assert(root);

        int closestVal = root->val;
        double minDiff = abs(root->val - target);
        while (root) {
            double diff = abs(root->val - target);
            if (diff < minDiff) {
                closestVal = root->val;
                minDiff = abs(root->val - target);
            }
            if (target < root->val) {
                root = root->left;
            }
            else if (root->val < target) {
                root = root->right;
            }
            else {
                break;
            }
        }

        return closestVal;
    }

    int closestValue(TreeNode* root, double target) {
        //return closestValue_Recursive(root, target);
        return closestValue_Iterative(root, target);
    }
};