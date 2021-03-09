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
    TreeNode* sortedArrayToBST_Recursive(vector<int>& nums, size_t bgn, size_t end) {
        if (end <= bgn) {
            return nullptr;
        }

        size_t mid = bgn + (end - bgn) / 2;
        return new TreeNode(nums[mid], sortedArrayToBST_Recursive(nums, bgn, mid), sortedArrayToBST_Recursive(nums, mid + 1, end));
    }

    TreeNode* sortedArrayToBST_Iterative(vector<int>& nums) {
        map<pair<size_t, size_t>, TreeNode*> m;

        stack<pair<pair<size_t, size_t>, bool>> stk;
        if (!nums.empty()) {
            stk.emplace(make_pair(0, nums.size()), false);
        }
        while (!stk.empty()) {
            size_t bgn = stk.top().first.first, end = stk.top().first.second;
            bool visited = stk.top().second;
            stk.pop();

            size_t mid = bgn + (end - bgn) / 2;
            if (visited) {
                TreeNode* root = new TreeNode(nums[mid]);
                if (bgn < mid) {
                    root->left = m[{bgn, mid}];
                }
                if ((mid + 1) < end) {
                    root->right = m[{mid + 1, end}];
                }
                m[{bgn, end}] = root;
            }
            else {
                stk.emplace(make_pair(bgn, end), true);
                if (bgn < mid) {
                    stk.emplace(make_pair(bgn, mid), false);
                }
                if ((mid + 1) < end) {
                    stk.emplace(make_pair(mid + 1, end), false);
                }
            }
        }

        auto itr = m.find(make_pair(0, nums.size()));
        return (itr != m.end() ? itr->second : nullptr);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //return sortedArrayToBST_Recursive(nums, 0, nums.size());
        return sortedArrayToBST_Iterative(nums);
    }
};