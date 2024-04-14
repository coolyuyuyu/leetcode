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
        std::function<int(TreeNode*, bool)> f = [&](TreeNode* root, int left) {
            if (!root) {
                return 0;
            }

            return
                (left && !root->left && !root->right ? root->val : 0)
                + f(root->left, true)
                + f(root->right, false);
        };

        return f(root, false);
    }

    int iterative(TreeNode* root) {
        int ret = 0;
        for (queue<pair<TreeNode*, bool>> q({{root, false}}); !q.empty();) {
            auto [root, left] = q.front();
            q.pop();

            if (!root) {
                continue;
            }

            if (left && !root->left && !root->right) {
                ret += root->val;
            }

            q.emplace(root->left, true);
            q.emplace(root->right, false);
        }

        return ret;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        //return recursive(root);
        return iterative(root);
    }
};
