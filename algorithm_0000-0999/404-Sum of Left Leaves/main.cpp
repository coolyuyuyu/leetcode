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
    int sumOfLeftLeaves_Recursive(TreeNode* root, bool leftChildOfParent = false) {
        if (!root) {
            return 0;
        }

        int sum = 0;

        sum += sumOfLeftLeaves_Recursive(root->left, true);
        if (!root->left && !root->right && leftChildOfParent) {
            sum += root->val;
        }
        sum += sumOfLeftLeaves_Recursive(root->right, false);

        return sum;
    }

    int sumOfLeftLeaves_Iterative(TreeNode* root) {
        int sum = 0;

        stack<pair<pair<TreeNode*, bool>, bool>> stk; // <<node, leftChildOfParent>, visited>
        if (root) {
            stk.emplace(make_pair(root, false), false);
        }
        while (!stk.empty()) {
            TreeNode* node = stk.top().first.first;
            bool leftChildOfParent = stk.top().first.second;
            bool visited = stk.top().second;
            stk.pop();

            if (visited) {
                if (!node->left && !node->right && leftChildOfParent) {
                    sum += node->val;
                }
            }
            else {
                if (node->right) {
                    stk.emplace(make_pair(node->right, false), false);
                }
                stk.emplace(make_pair(node, leftChildOfParent), true);
                if (node->left) {
                    stk.emplace(make_pair(node->left, true), false);
                }
            }
        }

        return sum;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        //return sumOfLeftLeaves_Recursive(root);
        return sumOfLeftLeaves_Iterative(root);
    }
};