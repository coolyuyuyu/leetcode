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
    int longestZigZag(TreeNode* root) {
        return recursive(root);
    }

    int recursive(TreeNode* root) {
        std::function<int(TreeNode*, int, bool)> dfs = [&dfs](TreeNode* root, int zlen, bool flag) {
            if (!root) {
                return zlen;
            }

            return std::max(
                dfs(root->left, (flag ? zlen : 0) + 1, false),
                dfs(root->right, (!flag ? zlen : 0) + 1, true));
        };

        return std::max(dfs(root->left, 1, false), dfs(root->right, 1, true)) - 1;
    }
};
