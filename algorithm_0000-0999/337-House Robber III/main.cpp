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
    int recursive(TreeNode* root) {
        // dp(root): the maximum amount of money from tree rooted at root and [not rub root, rub root]
        std::function<pair<int, int>(TreeNode*)> dp = [&](TreeNode* root) -> pair<int, int> {
            if (!root) {
                return {0, 0};
            }

            auto [lftRubN, lftRubY] = dp(root->left);
            auto [rhtRubN, rhtRubY] = dp(root->right);
            int rubN = std::max(lftRubN, lftRubY) + std::max(rhtRubN, rhtRubY);
            int rubY = root->val + lftRubN + rhtRubN;

            return {rubN, rubY};
        };

        auto [rubN, rubY] = dp(root);
        return std::max(rubN, rubY);
    }

    int iterative(TreeNode* root) {
        // dp(root): the maximum amount of money from tree rooted at root and [not rub root, rub root]
        unordered_map<TreeNode*, pair<int, int>> dp = {{nullptr, {0, 0}}};

        for (stack<pair<TreeNode*, bool>> stk({{root, false}}); !stk.empty();) {
            auto [node, visited] = stk.top();
            stk.pop();

            if (visited) {
                auto [lftRubN, lftRubY] = dp[node->left];
                auto [rhtRubN, rhtRubY] = dp[node->right];

                int rubN = std::max(lftRubN, lftRubY) + std::max(rhtRubN, rhtRubY);
                int rubY = node->val + lftRubN + rhtRubN;
                dp[node] = {rubN, rubY};
            }
            else {
                stk.emplace(node, true);
                if (node->right) {
                    stk.emplace(node->right, false);
                }
                if (node->left) {
                    stk.emplace(node->left, false);
                }
            }
        }

        auto [rubN, rubY] = dp[root];
        return std::max(rubN, rubY);
    }

    int rob(TreeNode* root) {
        //return recursive(root);
        return iterative(root);
    }
};
