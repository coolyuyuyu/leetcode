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
    void leaves(TreeNode* root, vector<int>& vals) {
        if (root) {
            leaves(root->left, vals);
            if (root->left == nullptr && root->right == nullptr) {
                vals.push_back(root->val);
            }
            leaves(root->right, vals);
        }
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> vals1;
        leaves(root1, vals1);

        vector<int> vals2;
        leaves(root2, vals2);

        return vals1 == vals2;
    }
};