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
    bool isCompleteTree(TreeNode* root) {
        queue<pair<TreeNode*, size_t>> q; // <node, id>;
        if (root) {
            q.emplace(root, 0);
        }

        for (size_t index = 0; !q.empty(); ++index) {
            TreeNode* node = q.front().first;
            size_t id = q.front().second;
            q.pop();

            if (id != index) {
                return false;
            }

            if (node->left) {
                q.emplace(node->left, id * 2 + 1);
            }
            if (node->right) {
                q.emplace(node->right, id * 2 + 2);
            }
        }

        return true;
    }
};