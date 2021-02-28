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

    int computeDepth(TreeNode* root, int level, unordered_map<TreeNode*, int>& levels) {
        if (!root) {
            return level;
        }

        levels.emplace(root, level + 1);
        int depthLft = computeDepth(root->left, level + 1, levels);
        int depthRht = computeDepth(root->right, level + 1, levels);
        return max(depthLft, depthRht);
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root, int depth, const unordered_map<TreeNode*, int>& levels) {
        if (!root) {
            return nullptr;
        }

        auto itr = levels.find(root);
        assert(itr != levels.end());
        if (itr->second == depth) {
            return root;
        }

        TreeNode* lft = subtreeWithAllDeepest(root->left, depth, levels);
        TreeNode* rht = subtreeWithAllDeepest(root->right, depth, levels);
        if (lft && rht) {
            return root;
        }
        if (lft) {
            return lft;
        }
        if (rht) {
            return rht;
        }
        return nullptr;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        unordered_map<TreeNode*, int> levels;
        size_t depth = computeDepth(root, 0, levels);
        return subtreeWithAllDeepest(root, depth, levels);
    }
};