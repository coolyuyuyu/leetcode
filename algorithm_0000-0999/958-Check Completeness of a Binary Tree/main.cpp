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
    bool isCompleteTree(TreeNode* root) {
        queue<pair<TreeNode*, size_t>> q;
        if (root) {
            q.emplace(root, 0);
        }

        size_t index = 0;
        while (!q.empty()) {
            size_t n = q.size();
            for (size_t i = 0; i < n; ++i) {
                TreeNode* node = q.front().first;
                size_t id = q.front().second;

                q.pop();

                if (id != index++) {
                    return false;
                }

                if (node->left) {
                    q.emplace(node->left, id * 2 + 1);
                    if (node->right) {
                        q.emplace(node->right, id * 2 + 2);
                    }
                }
                else {
                    if (node->right) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};