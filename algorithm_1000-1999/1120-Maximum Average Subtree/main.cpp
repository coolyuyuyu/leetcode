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
    double maximumAverageSubtree_Recursive(TreeNode* root, pair<int, int>& sumAndCnt) {
        if (!root) {
            sumAndCnt = {0, 0};
            return 0;
        }

        pair<int, int> lftSumAndCnt, rhtSumAndCnt;
        double lftMaxAvg = maximumAverageSubtree_Recursive(root->left, lftSumAndCnt);
        double rhtMaxAvg = maximumAverageSubtree_Recursive(root->right, rhtSumAndCnt);

        sumAndCnt = {lftSumAndCnt.first + root->val + rhtSumAndCnt.first, lftSumAndCnt.second + 1 + rhtSumAndCnt.second};

        double avg = static_cast<double>(sumAndCnt.first) / sumAndCnt.second;
        return max(avg, max(lftMaxAvg, rhtMaxAvg));
    }

    double maximumAverageSubtree_Iterative(TreeNode* root) {
        double maxAvg = 0.0;

        unordered_map<TreeNode*, pair<int, int>> m; // <node, <sum, cnt>>

        // postorder traversal
        stack<pair<TreeNode*, bool>> stk;
        if (root) {
            stk.emplace(root, false);
        }
        while (!stk.empty()) {
            TreeNode* node = stk.top().first;
            bool visited = stk.top().second;
            stk.pop();

            if (visited) {
                pair<int, int> lftSumAndCnt = (node->left ? m[node->left] : make_pair(0, 0));
                pair<int, int> rhtSumAndCnt = (node->right ? m[node->right] : make_pair(0, 0));
                pair<int, int> sumAndCnt = {lftSumAndCnt.first + node->val + rhtSumAndCnt.first, lftSumAndCnt.second + 1 + rhtSumAndCnt.second};

                double avg = static_cast<double>(sumAndCnt.first) / sumAndCnt.second;
                if (maxAvg < avg) {
                    maxAvg = avg;
                }

                m[node] = sumAndCnt;
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

        return maxAvg;
    }

    double maximumAverageSubtree(TreeNode* root) {
        pair<int, int> sumAndCnt;
        return maximumAverageSubtree_Recursive(root, sumAndCnt);

        //return maximumAverageSubtree_Iterative(root);
    }
};