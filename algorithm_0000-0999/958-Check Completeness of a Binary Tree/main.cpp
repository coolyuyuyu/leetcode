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
        queue<pair<TreeNode*, int>> q({{root, 0}});
        for (int index = 0; !q.empty();) {
            auto [node, id] = q.front();
            q.pop();

            if (!node) {
                continue;
            }
            if (id != index) {
                return false;
            }

            q.emplace(node->left, id * 2 + 1);
            q.emplace(node->right, id * 2 + 2);
            ++index;
        }

        return true;
    }
};
