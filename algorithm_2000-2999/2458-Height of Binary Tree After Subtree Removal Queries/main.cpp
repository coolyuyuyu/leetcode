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
    int dfs(TreeNode* root, int d, vector<int>& depths, vector<int>& heights, unordered_map<int, vector<int>>& d2heights) {
        if (!root) {
            return 0;
        }

        int h = std::max(dfs(root->left, d + 1, depths, heights, d2heights), dfs(root->right, d + 1, depths, heights, d2heights));
        depths[root->val] = d;
        heights[root->val] = h;
        d2heights[d].push_back(h);

        return h + 1;
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> depths(100005);
        vector<int> heights(100005);
        unordered_map<int, vector<int>> d2heights;

        dfs(root, 0, depths, heights, d2heights);
        for (auto& [d, heights] : d2heights) {
            std::partial_sort(heights.begin(), heights.begin() + std::min((size_t)2, heights.size()), heights.end(), std::greater<int>());
        }

        size_t n = queries.size();
        vector<int> ret(n);
        for (size_t i = 0; i < n; ++i) {
            int d = depths[queries[i]];
            if (d2heights[d].size() == 1) {
                ret[i] = d - 1;
            }
            else if (d2heights[d][0] == heights[queries[i]]) {
                ret[i] = d + d2heights[d][1];
            }
            else {
                ret[i] = d + d2heights[d][0];
            }
        }

        return ret;
    }
};
