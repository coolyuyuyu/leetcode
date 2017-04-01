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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> lists;
        queue<TreeNode*> nodes;
        if (root) {
            nodes.push(root);
        }
        while (!nodes.empty()) {
            size_t count = nodes.size();
            vector<int> nums;
            nums.reserve(count);
            for (size_t i = 0; i < count; ++i) {
                TreeNode* pNode = nodes.front();
                nodes.pop();
                nums.push_back(pNode->val);
                if (pNode->left) {
                    nodes.push(pNode->left);
                }
                if (pNode->right) {
                    nodes.push(pNode->right);
                }
            }
            lists.push_back(nums);
        }
        reverse(lists.begin(), lists.end());
        return lists;
    }
};