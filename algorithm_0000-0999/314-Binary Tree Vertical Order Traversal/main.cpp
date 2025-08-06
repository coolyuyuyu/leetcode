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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> m;
        for (queue<pair<TreeNode*, int>> q({{root, 0}}); !q.empty();) {
            auto [node, c] = q.front();
            q.pop();
            if (!node) { continue; }

            m[c].push_back(node->val);

            q.emplace(node->left, c - 1);
            q.emplace(node->right, c + 1);
        }

        vector<vector<int>> ret;
        for (const auto& [c, nums] : m) {
            ret.push_back(nums);
        }

        return ret;
    }
};
