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
    bool hasPathSum(TreeNode* root, int sum) {
        queue<pair<TreeNode*, int>> nodes;
        if (root) {
            nodes.push(pair<TreeNode*, int>(root, root->val));
        }

        bool success = false;
        while (!nodes.empty()) {
            const pair<TreeNode*, int>& p = nodes.front();
            if (p.first->left) {
                nodes.push(pair<TreeNode*, int>(p.first->left, p.second + p.first->left->val));
                if (p.first->right) {
                    nodes.push(pair<TreeNode*, int>(p.first->right, p.second + p.first->right->val));
                }
            }
            else {
                if (p.first->right) {
                    nodes.push(pair<TreeNode*, int>(p.first->right, p.second + p.first->right->val));
                }
                else {
                    if (p.second == sum) {
                        success = true;
                        break;
                    }
                }
            }

            nodes.pop();
        }

        return success;
    }
};