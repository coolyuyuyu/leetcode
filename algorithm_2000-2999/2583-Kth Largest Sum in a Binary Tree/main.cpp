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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> sums; // <level, sum>

        queue<pair<TreeNode*, int>> q({{root, 1}});
        while (!q.empty()) {
            for (int n = q.size(); 0 < n--;) {
                auto [root, level] = q.front();
                q.pop();

                if (!root) {
                    continue;
                }

                if (sums.size() <= level) {
                    sums.resize(level + 1);
                }

                sums[level] += root->val;

                q.emplace(root->left, level + 1);
                q.emplace(root->right, level + 1);
            }
        }
        if (sums.size() <= k) {
            return -1;
        }

        std::sort(sums.begin(), sums.end());
        return sums[sums.size() - k];
    }
};
