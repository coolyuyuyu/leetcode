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
        std::function<int(TreeNode*, int)> f = [&](TreeNode* root, int num) {
            if (!root) {
                return 0;
            }

            num = num * 10 + root->val;
            if (!root->left && !root->right) {
                return num;
            }
            return f(root->left, num) + f(root->right, num);
        };

        return f(root, 0);
    }

    int iterative(TreeNode* root) {
        int ret = 0;
        for (queue<pair<TreeNode*, int>> q({{root, 0}}); !q.empty();) {
            auto [root, num] = q.front();
            q.pop();

            if (!root) { continue; }

            num = num * 10 + root->val;
            if (!root->left && !root->right) {
                ret += num;
            }
            else {
                q.emplace(root->left, num);
                q.emplace(root->right, num);
            }
        }

        return ret;
    }

    int sumNumbers(TreeNode* root) {
        //return recursive(root);
        return iterative(root);
    }
};
