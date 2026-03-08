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
        vector<TreeNode*> nodes;
        std::function<void(TreeNode*)> traverse = [&](TreeNode* root) {
            if (!root) { return; }

            traverse(root->left);
            nodes.push_back(root);
            traverse(root->right);
        };
        traverse(root);

        std::function<TreeNode*(int, int)> build = [&](int lo, int hi) -> TreeNode* {
            if (lo > hi) { return nullptr; }

            int mid = lo + (hi - lo) / 2;
            TreeNode* root = nodes[mid];
            root->left = build(lo, mid - 1);
            root->right = build(mid + 1, hi);
            return root;
        };

        return build(0, nodes.size() - 1);
    }
};
