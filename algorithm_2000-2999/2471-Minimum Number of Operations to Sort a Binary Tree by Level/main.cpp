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
    int minSwap(vector<int>& nums) {
        if (nums.empty()) { return 0; }
        int n = nums.size();

        int indexes[n];
        std::iota(indexes, indexes + n, 0);
        std::sort(indexes, indexes + n, [&](int idx1, int idx2){ return nums[idx1] < nums[idx2]; });

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            while (indexes[i] != i) {
                std::swap(indexes[i], indexes[indexes[i]]);
                ++ret;
            }
        }

        return ret;
    };

    int minimumOperations(TreeNode* root) {
        int ret = 0;
        for (queue<TreeNode*> q({root}); !q.empty();) {
            vector<int> nums;
            for (int i = q.size(); 0 < i--;) {
                auto node = q.front();
                q.pop();

                if (!node) { continue;}
                nums.push_back(node->val);

                q.push(node->left);
                q.push(node->right);
            }
            ret += minSwap(nums);
        }

        return ret;
    }
};
