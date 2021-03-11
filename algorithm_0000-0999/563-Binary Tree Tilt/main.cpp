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
    int findTilt_Recursive(TreeNode* root, int& sum) {
        if (!root) {
            sum = 0;
            return 0;
        }

        int lftSum;
        int lftSumOfTilt = findTilt_Recursive(root->left, lftSum);
        int rhtSum;
        int rhtSumOfTilt = findTilt_Recursive(root->right, rhtSum);

        sum = lftSum + root->val + rhtSum;
        return lftSumOfTilt + abs(lftSum - rhtSum) + rhtSumOfTilt;
    }

    int findTilt_Iterative(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int sumOfTilt = 0;
        map<TreeNode*, int> m; // <node, sum>

        // postorder traversal
        stack<pair<TreeNode*, bool>> stk;
        stk.emplace(root, false);
        while (!stk.empty()) {
            TreeNode* node = stk.top().first;
            if (stk.top().second) {
                stk.pop();

                int lftSum = (node->left ? m[node->left] : 0);
                int rhtSum = (node->right ? m[node->right] : 0);
                m[node] = lftSum + node->val + rhtSum;
                sumOfTilt += abs(lftSum - rhtSum);
            }
            else {
                stk.top().second = true;
                if (node->right) {
                    stk.emplace(node->right, false);
                }
                if (node->left) {
                    stk.emplace(node->left, false);
                }
            }
        }

        return sumOfTilt;
    }

    int findTilt(TreeNode* root) {
        //int sum;
        //return findTilt_Recursive(root, sum);

        return findTilt_Iterative(root);
    }
};