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
    int longestConsecutive(TreeNode* root) {
        int ret = 0;
        std::function<pair<int, int>(TreeNode*)> f = [&](TreeNode* root) {
            if (!root) { return make_pair(0, 0); }

            int inc = 1, dec = 1;
            if (root->left) {
                auto [lftInc, lftDec] = f(root->left);
                if (root->val + 1 == root->left->val) {
                    inc = lftInc + 1;
                }
                else if (root->val - 1 == root->left->val) {
                    dec = lftDec + 1;
                }
            }
            if (root->right) {
                auto [rhtInc, rhtDec] = f(root->right);
                if (root->val + 1 == root->right->val) {
                    inc = std::max(inc, rhtInc + 1);
                }
                else if (root->val - 1 == root->right->val) {
                    dec = std::max(dec, rhtDec + 1);
                }
            }

            ret = std::max(ret, inc + dec - 1);

            return make_pair(inc, dec);
        };
        f(root);

        return ret;
    }
};
