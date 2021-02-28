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
    int sumTree(TreeNode* root, unordered_map<int, size_t>& sumCounts) {
        if (!root) {
            return 0;
        }

        int sum = root->val + sumTree(root->left, sumCounts) + sumTree(root->right, sumCounts);
        ++sumCounts[sum];
        return sum;
    }

    bool checkEqualTree(TreeNode* root) {
        unordered_map<int, size_t> sumCounts;
        int sum = sumTree(root, sumCounts);
        if (sum % 2 == 0) {
            if (sum == 0) {
                return 2 <= sumCounts[0];
            }
            else {
                return sumCounts.find(sum / 2) != sumCounts.end();
            }
        }
        else {
            return false;
        }
    }
};