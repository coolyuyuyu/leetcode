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
    int findBottomLeftValue(TreeNode* root) {
        int val = root->val;

        queue<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            val = nodes.front()->val;

            for (size_t n = nodes.size(); n > 0; --n) {
                TreeNode* node = nodes.front();
                nodes.pop();

                TreeNode* lft = node->left;
                if (lft) {
                    nodes.push(lft);
                }
                TreeNode* rht = node->right;
                if (rht) {
                    nodes.push(rht);
                }
            }
        }

        return val;
    }
};
