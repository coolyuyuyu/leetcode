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
    int findFrequentTreeSum(TreeNode* root, unordered_map<int, int>& sumCounts, int& maxSumCount) {
        if (!root) {
            return 0;
        }

        int sum = root->val + findFrequentTreeSum(root->left, sumCounts, maxSumCount) + findFrequentTreeSum(root->right, sumCounts, maxSumCount);
        ++sumCounts[sum];
        maxSumCount = max(maxSumCount, sumCounts[sum]);

        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> sumCounts;
        int maxSumCount = 0;
        findFrequentTreeSum(root, sumCounts, maxSumCount);

        vector<int> sums;
        for (const pair<int, int>& p : sumCounts) {
            if (p.second == maxSumCount) {
                sums.emplace_back(p.first);
            }
        }

        return sums;
    }
};