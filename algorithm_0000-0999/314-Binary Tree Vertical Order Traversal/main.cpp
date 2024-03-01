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
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 0);
        while (!q.empty()) {
            auto [node, index] = q.front();
            q.pop();
            if (!node) { continue; }

            m[index].push_back(node->val);
            q.emplace(node->left, index - 1);
            q.emplace(node->right, index + 1);
        }

        vector<vector<int>> ret;
        for (const auto& [_, nums] : m) {
            ret.push_back(nums);
        }

        return ret;
    }
};
