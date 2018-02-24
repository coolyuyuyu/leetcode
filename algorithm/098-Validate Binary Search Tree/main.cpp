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
    bool isValidBST(TreeNode* root) {
        TreeNode* preNode = NULL;

        stack<TreeNode*> nodes;
        while (root || !nodes.empty()) {
            if (root) {
                nodes.push(root);
                root = root->left;
            }
            else {
                root = nodes.top();
                nodes.pop();

                if (preNode && (preNode && preNode->val >= root->val)) {
                    return false;
                }

                preNode = root;
                root = root->right;
            }
        }

        return true;
    }
};