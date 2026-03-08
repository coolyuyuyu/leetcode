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
    int sumRootToLeaf(TreeNode* root) {
        std::function<int(TreeNode*, int)> f = [&](TreeNode* root, int num) {
            if (!root) {
                return 0;
            }

            num = (num << 1) + root->val;
            if (!root->left && !root->right) {
                return num;
            }
            else {
                return f(root->left, num) + f(root->right, num);
            }
        };

        return f(root, 0);
    }
};
