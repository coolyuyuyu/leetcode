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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int height = 0; {
            queue<TreeNode*> q;
            if (root) { q.push(root); }
            for (; !q.empty(); ++height) {
                for (int i = q.size(); 0 < i--;) {
                    TreeNode* node = q.front();
                    q.pop();

                    if (node->left) { q.push(node->left); }
                    if (node->right) { q.push(node->right); }
                }
            }
        }

        std::function<TreeNode*(TreeNode*, int)> dfs = [&](TreeNode* root, int d) {
            if (!root || d + 1 == height) {
                return root;
            }

            TreeNode* lft = dfs(root->left, d + 1);
            TreeNode* rht = dfs(root->right, d + 1);
            if (lft && rht) {
                return root;
            }
            else {
                return lft ? lft : rht;
            }
        };

        return dfs(root, 0);
    }
};
