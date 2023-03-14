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
    int recursive(TreeNode* root, int num = 0) {
        if (!root) {
            return 0;
        }

        num = num * 10 + root->val;
        if (!(root->left) && !(root->right)) {
            return num;
        }
        return recursive(root->left, num) + recursive(root->right, num);
    }

    int iterative(TreeNode* root) {
        int sum = 0;
        queue<pair<TreeNode*, int>> q({{root, 0}});
        while (!q.empty()) {
            auto [root, num] = q.front();
            q.pop();

            if (!root) {
                continue;
            }

            num = num * 10 + root->val;
            if (!(root->left) && !(root->right)) {
                sum += num;
            }
            else {
                q.emplace(root->left, num);
                q.emplace(root->right, num);
            }
        }

        return sum;
    }

    int sumNumbers(TreeNode* root) {
        //return recursive(root, 0);
        return iterative(root);
    }
};
