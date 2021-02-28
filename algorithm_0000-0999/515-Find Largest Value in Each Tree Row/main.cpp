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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }

        vector<int> nums;
        while (!q.empty()) {
            int num = q.front()->val;
            size_t n = q.size();
            for (size_t i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();


                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }

                if (num < node->val) {
                    num = node->val;
                }
            }
            nums.emplace_back(num);
        }

        return nums;
    }
};