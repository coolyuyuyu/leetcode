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
        std::function<int(TreeNode*, int)> f = [&](TreeNode* root, int parity) {
            if (!root) { return 0; }

            parity ^= (1 << root->val);
            if (root->left == nullptr && root->right == nullptr) {
                return __builtin_popcount(parity) <= 1 ? 1 : 0;
            }
            return f(root->left, parity) + f(root->right, parity);
        };

        return f(root, 0);
    }

    int iterative(TreeNode* root) {
        int ret = 0;
        for (queue<pair<TreeNode*, int>> q({{root, 0}}); !q.empty();) {
            auto [node, parity] = q.front();
            q.pop();

            if (!node) { continue; }
            parity ^= (1 << node->val);
            if (node->left == nullptr && node->right == nullptr) {
                ret += (__builtin_popcount(parity) <= 1 ? 1 : 0);
            }

            q.emplace(node->left, parity);
            q.emplace(node->right, parity);
        }

        return ret;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        //return recursive(root);
        return iterative(root);
    }
};
