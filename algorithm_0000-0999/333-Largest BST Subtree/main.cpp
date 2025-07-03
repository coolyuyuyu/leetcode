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
    int largestBSTSubtree(TreeNode* root) {
        std::function<std::tuple<int, int, int>(TreeNode*)> f = [&](TreeNode* root) {
            if (!root) {
                return std::make_tuple(0, INT_MAX, INT_MIN);
            }

            auto [lftCnt, lftMin, lftMax] = f(root->left);
            auto [rhtCnt, rhtMin, rhtMax] = f(root->right);
            if (lftMax < root->val && root->val < rhtMin) {
                return std::make_tuple(lftCnt + 1 + rhtCnt, std::min(lftMin, root->val), std::max(root->val, rhtMax));
            }
            else {
                return std::make_tuple(std::max(lftCnt, rhtCnt), INT_MIN, INT_MAX);
            }
        };

        auto [ret, _1, _2] = f(root);
        return ret;
    }
};
