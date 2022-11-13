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
    // cycle sort
    int minSwaps(vector<int>& nums) {
        vector<size_t> indexes(nums.size());
        std::iota(indexes.begin(), indexes.end(), (size_t)0);
        std::sort(indexes.begin(), indexes.end(), [&](size_t i1, size_t i2) { return nums[i1] < nums[i2]; });

        int cnt = 0;
        for (size_t i = 0; i < indexes.size(); ++i) {
            while (indexes[i] != indexes[indexes[i]]) {
                std::swap(indexes[i], indexes[indexes[i]]);
                ++cnt;
            }
        }

        return cnt;;
    }

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> nodes;
        if (root) {
            nodes.push(root);
        }

        int cnt = 0;
        while (!nodes.empty()) {
            vector<int> vals;
            for (size_t i = 0, n = nodes.size(); i < n; ++i) {
                TreeNode* node = nodes.front();
                nodes.pop();
                if (node->left) {
                    nodes.push(node->left);
                }
                if (node->right) {
                    nodes.push(node->right);
                }

                vals.push_back(node->val);
            }
            cnt += minSwaps(vals);
        }

        return cnt;
    }
};
