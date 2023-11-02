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
    int averageOfSubtree(TreeNode* root) {
        int ret = 0;
        std::function<pair<int, int>(TreeNode*)> f = [&](TreeNode* root) -> pair<int, int> {
            if (!root) { return {0, 0}; }

            auto [lftSum, lftCnt] = f(root->left);
            auto [rhtSum, rhtCnt] = f(root->right);
            int sum = lftSum + root->val + rhtSum, cnt = lftCnt + 1 + rhtCnt;
            if (sum / cnt == root->val) {
                ++ret;
            }

            return {sum, cnt};
        };
        f(root);

        return ret;
    }
};
