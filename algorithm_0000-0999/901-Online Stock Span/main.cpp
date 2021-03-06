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
    pair<TreeNode*, size_t> findParentDepth(TreeNode* parent, TreeNode* node, int val, size_t depth) {
        if (!node) {
            return {nullptr, 0};
        }

        if (node->val == val) {
            return {parent, depth};
        }
        else {
            auto p = findParentDepth(node, node->left, val, depth + 1);
            if (p.first) {
                return p;
            }
            else {
                return findParentDepth(node, node->right, val, depth + 1);
            }
        }
    }

    bool isCousins(TreeNode* root, int x, int y) {
        auto p1 = findParentDepth(nullptr, root, x, 0);
        auto p2 = findParentDepth(nullptr, root, y, 0);
        return (p1.first != p2.first && p1.second == p2.second);
    }
};