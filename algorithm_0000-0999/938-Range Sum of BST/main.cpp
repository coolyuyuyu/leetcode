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
    int recursive(TreeNode* root, int low, int high) {
        std::function<int(TreeNode*, int, int)> f = [&](TreeNode* root, int l, int h) {
            if (!root || h < low || high < l) { return 0; }

            int ret = 0;
            if (low <= root->val && root->val <= high) {
                ret += root->val;
            }
            return ret + f(root->left, l, root->val - 1) + f(root->right, root->val + 1, h);
        };

        return f(root, INT_MIN, INT_MAX);
    }

    int iterative(TreeNode* root, int low, int high) {
        int ret = 0;
        for (queue<tuple<TreeNode*, int, int>> q({{root, INT_MIN, INT_MAX}}); !q.empty();) {
            auto [root, l, h] = q.front();
            q.pop();

            if (!root || h < low || high < l) { continue; }

            if (low <= root->val && root->val <= high) {
                ret += root->val;
            }
            q.emplace(root->left, l, root->val - 1);
            q.emplace(root->right, root->val + 1, h);
        }

        return ret;
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        //return recursive(root, low, high);
        return iterative(root, low, high);
    }
};
