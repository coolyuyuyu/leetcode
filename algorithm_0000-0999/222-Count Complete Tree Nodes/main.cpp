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
    int countNodes(TreeNode* root) {
        size_t count = 0;

        deque<pair<TreeNode*, size_t>> q;
        if (root) {
            q.emplace_back(root, 1);
        }
        while (!q.empty()) {
            count = q.back().second;

            size_t n = q.size();
            for (size_t i = 0; i < n; ++i) {
                pair<TreeNode*, size_t> p = q.front();
                q.pop_front();

                if (p.first->left) {
                    q.emplace_back(p.first->left, p.second * 2);
                }
                if (p.first->right) {
                    q.emplace_back(p.first->right, p.second * 2 + 1);
                }
            }
        }

        return count;
    }
};