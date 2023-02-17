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
    int recursive(TreeNode* root, int minVal = INT_MIN, int maxVal = INT_MAX) {
        if (!root) {
            return INT_MAX;
        }

        return std::min({
            minVal != INT_MIN ? (root->val - minVal) : INT_MAX,
            maxVal != INT_MAX ? (maxVal - root->val) : INT_MAX,
            recursive(root->left, minVal, root->val),
            recursive(root->right, root->val, maxVal)});
    }

    int iterative(TreeNode* root) {
        int minDiff = INT_MAX;
        stack<tuple<TreeNode*, int, int>> stk({{root, INT_MIN, INT_MAX}});
        while (!stk.empty()) {
            auto [root, minVal, maxVal] = stk.top();
            stk.pop();

            if (!root) {
                continue;
            }
            minDiff = std::min({
                minDiff,
                minVal != INT_MIN ? (root->val - minVal) : INT_MAX,
                maxVal != INT_MAX ? (maxVal - root->val) : INT_MAX});

            stk.emplace(root->right, root->val, maxVal);
            stk.emplace(root->left, minVal, root->val);
        }

        return minDiff;
    }

    int minDiffInBST(TreeNode* root) {
        //return recursive(root);
        return iterative(root);
    }
};
