/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* pRoot = NULL;
        sortedArrayToBSTHelper(nums, 0, nums.size() - 1, &pRoot);
        return pRoot;
    }

    void sortedArrayToBSTHelper(const vector<int>& nums, int bgn, int end, TreeNode** ppRoot) {
        if (bgn <= end) {
            int mid = bgn + (end - bgn) / 2;
            *ppRoot = new TreeNode(nums[mid]);
            sortedArrayToBSTHelper(nums, bgn, mid - 1, &((*ppRoot)->left));
            sortedArrayToBSTHelper(nums, mid + 1, end, &((*ppRoot)->right));
        }
    }
};