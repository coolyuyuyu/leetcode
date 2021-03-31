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
        TreeNode* pRoot = nullptr;

        // level order traversal
        queue<tuple<TreeNode**, size_t, size_t>> q; // <node, bgn, end>
        if (!nums.empty()) {
            q.emplace(&pRoot, 0, nums.size());
        }
        while (!q.empty()) {
            TreeNode** ppNode = get<0>(q.front());
            size_t bgn = get<1>(q.front());
            size_t end = get<2>(q.front());
            q.pop();

            size_t mid = bgn + (end - bgn) / 2;
            *ppNode = new TreeNode(nums[mid]);

            if (bgn < mid) {
                q.emplace(&((*ppNode)->left), bgn, mid);
            }
            if ((mid + 1) < end) {
                q.emplace(&((*ppNode)->right), mid + 1, end);
            }
        }

        return pRoot;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //return sortedArrayToBST_Recursive(nums, 0, nums.size());
        return sortedArrayToBST_Iterative(nums);
    }
};