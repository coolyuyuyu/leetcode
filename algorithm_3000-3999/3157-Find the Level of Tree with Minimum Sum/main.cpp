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
    int minimumLevel(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }

        long minSum = LONG_MAX;
        int ret = 0;
        for (int lvl = 1; !q.empty(); ++lvl) {
            long sum = 0;
            for (int n = q.size(); 0 < n--;) {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }

            if (sum < minSum) {
                ret = lvl;
                minSum = sum;
            }
        }

        return ret;
    }
};
