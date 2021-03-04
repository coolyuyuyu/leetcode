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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }

        bool flip = false;
        vector<vector<int>> ret;
        while (!q.empty()) {
            size_t len = q.size();
            ret.emplace_back(len);
            for (size_t i = 0; i < len; ++i) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }

                ret.back()[flip ? (len - i - 1) : i] = node->val;
            }

            flip = !flip;
        }
        return ret;
    }
};