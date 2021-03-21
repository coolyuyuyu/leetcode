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
    pair<int, int> rob_Recursibve(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }

        auto lftResult = rob_Recursibve(root->left);
        auto rhtResult = rob_Recursibve(root->right);

        int robbedN = max(lftResult.first, lftResult.second) + max(rhtResult.first, rhtResult.second);
        int robbedY = lftResult.first + root->val + rhtResult.first;
        return {robbedN, robbedY};
    }

    int rob_Iterative(TreeNode* root) {
        if (!root) {
            return 0;
        }

        map<TreeNode*, pair<int, int>> m; // <node, <robbedN, robbedY>>

        // postorder traversal
        stack<pair<TreeNode*, bool>> stk({{root, false}});
        while (!stk.empty()) {
            TreeNode* node = stk.top().first;
            bool visited = stk.top().second;
            stk.pop();

            if (visited) {
                pair<int, int> lftResult = (node->left ? m[node->left] : make_pair(0, 0));
                pair<int, int> rhtResult = (node->right ? m[node->right] : make_pair(0, 0));
                int robbedN = max(lftResult.first, lftResult.second) + max(rhtResult.first, rhtResult.second);
                int robbedY = lftResult.first + node->val + rhtResult.first;
                m[node] = {robbedN, robbedY};
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

        return max(m[root].first, m[root].second);
    }

    int rob(TreeNode* root) {
        //auto result = rob_Recursibve(root);
        //return max(result.first, result.second);

        return rob_Iterative(root);
    }
};