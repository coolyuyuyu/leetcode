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
    int sumNumbers_Recursive(TreeNode* root, int num = 0) {
        if (!root) {
            return 0;
        }

        num = num * 10 + root->val;
        if (!root->left && !root->right) {
            return num;
        }
        else {
            return sumNumbers_Recursive(root->left, num) + sumNumbers_Recursive(root->right, num);
        }
    }

    int sumNumbers_Iterative(TreeNode* root) {
        int sum = 0;

        // level order traversal
        queue<pair<TreeNode*, int>> q;
        if (root) {
            q.emplace(root, 0);
        }
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int num = q.front().second;
            q.pop();

            num = num * 10 + node->val;
            if (!node->left && !node->right) {
                sum += num;
            }
            else {
                if (node->left) {
                    q.emplace(node->left, num);
                }
                if (node->right) {
                    q.emplace(node->right, num);
                }
            }
        }

        return sum;
    }

    int sumNumbers(TreeNode* root) {
        //return sumNumbers_Recursive(root);
        return sumNumbers_Iterative(root);
    }
};