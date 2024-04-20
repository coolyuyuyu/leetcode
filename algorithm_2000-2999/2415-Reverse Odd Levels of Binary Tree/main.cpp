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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q({root});
        for (int d = 0; !q.empty(); ++d) {
            vector<TreeNode*> nodes;
            for (int i = q.size(); 0 < i--;) {
                TreeNode* node = q.front();
                q.pop();

                if (d & 1) {
                    nodes.push_back(node);
                }

                if (!node->left) { continue; }
                q.push(node->left);
                q.push(node->right);
            }

            for (int i = 0; i * 2 < nodes.size(); ++i) {
                std::swap(nodes[i]->val, nodes[nodes.size() - i - 1]->val);
            }
        }

        return root;
    }
};
