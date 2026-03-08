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
    bool isBalanced(TreeNode* root) {
        std::function<pair<bool, int>(TreeNode*)> f = [&](TreeNode* root) -> pair<bool, int> {
            if (!root) { return {true, 0}; }

            auto [lftBalanced, lftHeight] = f(root->left);
            if (!lftBalanced) { return {false, -1}; }
            auto [rhtBalanced, rhtHeight] = f(root->right);
            if (!rhtBalanced) { return {false, -1}; }

            if (std::abs(lftHeight - rhtHeight) > 1) { return {false, -1}; }

            return {true, 1 + std::max(lftHeight, rhtHeight)};
        };

        return f(root).first;
    }
};
