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
    int pathSum(TreeNode* root, int sum) {
        int count = pathSumFrom(root, sum);
        if (root) {
            count += pathSum(root->left, sum);
            count += pathSum(root->right, sum);
        }
        
        return count;
    }


    int pathSumFrom(TreeNode* root, int sum) {
        if (root) {
            int count = 0;
            if (root->val == sum) {
                ++count;
            }
            count += pathSumFrom(root->left, sum - root->val);
            count += pathSumFrom(root->right, sum - root->val);

            return count;
        }
        else {
            return 0;
        }
    }
};