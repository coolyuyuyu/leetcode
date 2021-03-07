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
    void tree2str_Recursive(TreeNode* root, ostringstream& oss) {
        if (!root) {
            return;
        }

        oss << root->val;
        if (root->left || root->right) {
            oss << "(";
            tree2str_Recursive(root->left, oss);
            oss << ")";

            if (root->right) {
                oss << "(";
            }
            tree2str_Recursive(root->right, oss);
            if (root->right) {
                oss << ")";
            }
        }
    }

    string tree2str(TreeNode* root) {
        ostringstream oss;
        tree2str_Recursive(root, oss);

        return oss.str();
    }
};