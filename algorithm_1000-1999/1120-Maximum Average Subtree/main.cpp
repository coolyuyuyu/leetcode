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
    double recursive(TreeNode* root) {
        double maxAvg = 0.0;
        std::function<pair<int, int>(TreeNode*)> f = [&](TreeNode* root) {
            if (!root) { return pair<int, int>{0, 0}; }

            auto [lftSum, lftCnt] = f(root->left);
            auto [rhtSum, rhtCnt] = f(root->right);

            int sum = root->val + lftSum + rhtSum;
            int cnt = 1 + lftCnt + rhtCnt;

            maxAvg = std::max(maxAvg, 1.0 * sum / cnt);

            return pair<int, int>{sum, cnt};
        };
        f(root);

        return maxAvg;
    }

    double iterative(TreeNode* root) {
        double maxAvg = 0.0;
        unordered_map<TreeNode*, pair<int, int>> m;
        m[nullptr] = pair<int, int>{0, 0};
        for (stack<pair<TreeNode*, bool>> stk({{root, false}}); !stk.empty();) {
            auto [node, visited] = stk.top();
            stk.pop();

            if (!node) { continue; }

            if (visited) {
                auto [lftSum, lftCnt] = m[node->left];
                auto [rhtSum, rhtCnt] = m[node->right];

                int sum = node->val + lftSum + rhtSum;
                int cnt = 1 + lftCnt + rhtCnt;

                maxAvg = std::max(maxAvg, 1.0 * sum / cnt);

                m[node] = {sum, cnt};
            }
            else {
                stk.emplace(node, true);
                stk.emplace(node->right, false);
                stk.emplace(node->left, false);
            }
        }

        return maxAvg;
    }

    double maximumAverageSubtree(TreeNode* root) {
        //return recursive(root);
        return iterative(root);
    }
};
