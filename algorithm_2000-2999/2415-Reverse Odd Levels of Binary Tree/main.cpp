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
                auto node = q.front();
                q.pop();

                if (d & 1) {
                    nodes.push_back(node);
                }

                if (node->left) { q.push(node->left);}
                if (node->right) { q.push(node->right); }
            }
            for (int lft = 0, rht = nodes.size() - 1; lft < rht; ++lft, --rht) {
                std::swap(nodes[lft]->val, nodes[rht]->val);
            }
        }

        return root;
    }
};
