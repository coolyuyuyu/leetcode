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
    void dfs(TreeNode* node, TreeNode* parent, size_t& count, unordered_set<TreeNode*>& monitored) {
        if (!node) {
            return;
        }

        dfs(node->left, node, count, monitored);
        dfs(node->right, node, count, monitored);
        if ((monitored.find(node->left) == monitored.end()) ||
            (monitored.find(node->right) == monitored.end()) ||
            (parent == nullptr && monitored.find(node) == monitored.end())) {
            ++count;
            monitored.emplace(parent);
            monitored.emplace(node);
            monitored.emplace(node->left);
            monitored.emplace(node->right);
        }
    }

    int minCameraCover(TreeNode* root) {
        unordered_set<TreeNode*> monitored;
        monitored.emplace(nullptr);

        size_t count = 0;
        dfs(root, nullptr, count, monitored);
        return count;
    }
};