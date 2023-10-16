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
    int M = 1e9 + 7;

    int topdnDFS(TreeNode* root) {
        std::function<int(TreeNode*)> computeSum = [&](TreeNode* root) {
            if (!root) {
                return 0;
            }

            root->val += computeSum(root->left) + computeSum(root->right);
            return root->val;
        };
        computeSum(root);

        long long sum = root->val;
        long long ans = 0;
        std::function<void(TreeNode*)> calcSplitPdt = [&](TreeNode* root) {
            if (!root) {
                return;
            }
            ans = std::max(ans, (sum - root->val) * root->val);

            calcSplitPdt(root->right);
            calcSplitPdt(root->left);
        };
        calcSplitPdt(root);

        return ans % M;
    }

    int maxProduct(TreeNode* root) {
        return topdnDFS(root);
    }
};
