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
    TreeNode* findNearestRightNode_Iterative(TreeNode* root, TreeNode* u) {
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }
        while (!q.empty()) {
            TreeNode* pPre = nullptr;
            for (size_t i = q.size(); 0 < i; --i) {
                TreeNode* node = q.front();
                q.pop();

                if (node == u) {
                    return pPre;
                }
                pPre = node;

                if (node->right) {
                    q.push(node->right);
                }
                if (node->left) {
                    q.push(node->left);
                }
            }
        }

        return nullptr;
    }

    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        return findNearestRightNode_Iterative(root, u);
    }
};
