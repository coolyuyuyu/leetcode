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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vals;
        std::function<void(TreeNode*)> traverse = [&](TreeNode* root) {
            if (!root) { return; }

            traverse(root->left);
            vals.push_back(root->val);
            traverse(root->right);
        };
        traverse(root);

        std::function<TreeNode*(int, int)> build = [&](int lft, int rht) -> TreeNode* {
            if (lft > rht) { return nullptr; }

            int mid = lft + (rht - lft) / 2;
            TreeNode* root = new TreeNode(vals[mid]);
            root->left = build(lft, mid - 1);
            root->right = build(mid + 1, rht);
            return root;
        };

        return build(0, vals.size() - 1);
    }
};
