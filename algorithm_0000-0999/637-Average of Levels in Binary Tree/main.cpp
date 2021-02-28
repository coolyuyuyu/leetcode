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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> nodes;
        if (root) {
            nodes.push(root);
        }

        vector<double> averages;
        while (!nodes.empty()) {
            double sum = 0;
            size_t n = nodes.size();
            for (size_t i = 0; i < n; ++i) {
                TreeNode* node = nodes.front();
                nodes.pop();

                sum += node->val;

                if (node->left) {
                    nodes.push(node->left);
                }
                if (node->right) {
                    nodes.push(node->right);
                }
            }
            averages.push_back(sum / n);
        }

        return averages;
    }
};