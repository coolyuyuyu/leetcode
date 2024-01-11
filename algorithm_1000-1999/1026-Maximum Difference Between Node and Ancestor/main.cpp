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
    int recursive(TreeNode* root) {
        std::function<int(TreeNode*, int, int)> f = [&](TreeNode* root, int mn, int mx) {
            if (!root) { return 0; }

            mn = std::min(mn, root->val);
            mx = std::max(mx, root->val);
            return std::max({mx - mn, f(root->left, mn, mx), f(root->right, mn, mx)});
        };

        return f(root, root->val, root->val);
    }

    int iterative(TreeNode* root) {
        int ret = 0;
        for (queue<tuple<TreeNode*, int, int>> q({{root, root->val, root->val}}); !q.empty();) {
            auto [root, mn, mx] = q.front();
            q.pop();

            if (!root) { continue; }

            mn = std::min(mn, root->val);
            mx = std::max(mx, root->val);
            ret = std::max(ret, mx - mn);

            q.emplace(root->left, mn, mx);
            q.emplace(root->right, mn, mx);
        }

        return ret;
    }

    int maxAncestorDiff(TreeNode* root) {
        //return recursive(root);
        return iterative(root);
    }
};
