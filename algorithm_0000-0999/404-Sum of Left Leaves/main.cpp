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
    int recursive(TreeNode* root, bool left = false) {
        if (!root) {
            return 0;
        }

        int ret = (left && !root->left && !root->right? root->val : 0)
            + recursive(root->left, true)
            + recursive(root->right, false);
        return ret;
    }

    int iterative(TreeNode* root) {
        queue<pair<TreeNode*, bool>> q({{root, false}});

        int ret = 0;
        while (!q.empty()) {
            auto [node, left] = q.front();
            q.pop();

            if (!node) {
                continue;
            }

            if (left && !node->left && !node->right) {
                ret += node->val;
            }

            q.emplace(node->left, true);
            q.emplace(node->right, false);
        }

        return ret;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        //return recursive(root);
        return iterative(root);
    }
};
