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
    int findDistance(TreeNode* root, int p, int q) {
        int ret = -1;
        std::function<pair<int, int>(TreeNode* root)> dfs = [&](TreeNode* root) -> pair<int, int> {
            if (!root) { return {-1, -1}; };
            if (ret != -1) { return {-1, -1}; };

            auto [aLft, bLft] = dfs(root->left);
            auto [aRht, bRht] = dfs(root->right);

            int a = -1;
            if (aLft != -1) {
                a = aLft + 1;
            }
            else if (aRht != -1) {
                a = aRht + 1;
            }
            else if (root->val == p) {
                a = 0;
            }

            int b = -1;
            if (bLft != -1) {
                b = bLft + 1;
            }
            else if (bRht != -1) {
                b = bRht + 1;
            }
            else if (root->val == q) {
                b = 0;
            }

            if (ret == -1 && a != -1 && b != -1) {
                ret = a + b;
            }

            return {a, b};
        };
        dfs(root);

        return ret;
    }
};
