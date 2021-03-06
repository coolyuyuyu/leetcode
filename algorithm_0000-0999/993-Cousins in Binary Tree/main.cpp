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
    pair<TreeNode*, int> findParentDepth_Recursive(TreeNode* parent, TreeNode* node, int val, size_t depth) {
        if (!node) {
            return {nullptr, -1};
        }

        if (node->val == val) {
            return {parent, depth - 1};
        }
        else {
            auto p = findParentDepth_Recursive(node, node->left, val, depth + 1);
            if (p.first) {
                return p;
            }
            else {
                return findParentDepth_Recursive(node, node->right, val, depth + 1);
            }
        }
    }

    pair<TreeNode*, int> findParentDepth_Iterative(TreeNode* root, int val) {
        if (!root) {
            return {nullptr, -1};
        }

        stack<pair<TreeNode*, pair<TreeNode*, int>>> stk; // <node, <parent, depth>>
        stk.emplace(root, make_pair(nullptr, -1));
        while (!stk.empty()) {
            TreeNode* parent = stk.top().second.first;
            TreeNode* node = stk.top().first;
            int depth = stk.top().second.second;
            stk.pop();

            if (node->val == val) {
                return {parent, depth};
            }

            if (node->right) {
                stk.emplace(node->right, make_pair(node, depth + 1));
            }
            if (node->left) {
                stk.emplace(node->left, make_pair(node, depth + 1));
            }
        }

        return {nullptr, -1};
    }

    bool isCousins(TreeNode* root, int x, int y) {
        //auto p1 = findParentDepth_Recursive(nullptr, root, x, 0);
        //auto p2 = findParentDepth_Recursive(nullptr, root, y, 0);

        auto p1 = findParentDepth_Iterative(root, x);
        auto p2 = findParentDepth_Iterative(root, y);

        return (p1.first != p2.first && p1.second == p2.second);
    }
};
