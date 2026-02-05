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
    int levelMedian(TreeNode* root, int level) {
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }

        for (int i = 0; i < level; ++i) {
            for (int j = q.size(); 0 < j--;) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) { q.push(node->left); }
                if (node->right) { q.push(node->right); }
            }
        }

        if (q.empty()) { return -1; }

        int n = q.size();
        for (int i = 0, n = q.size() / 2; i < n; ++i) {
            q.pop();
        }

        return q.front()->val;
    }
};
