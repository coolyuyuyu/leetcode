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
    int recursive(TreeNode* root) {
        if (!root) { return 0; }
        return 1 + max(recursive(root->left), recursive(root->right));
    }

    int iterative(TreeNode* root) {
        int depth = -1;
        for (queue<TreeNode*> q({root}); !q.empty(); ++depth) {
            for (int n = q.size(); 0 < n--;) {
                root = q.front();
                q.pop();

                if (!root) { continue; }

                q.push(root->left);
                q.push(root->right);
            }
        }

        return depth;
    }

    int maxDepth(TreeNode* root) {
        //return recursive(root);
        return iterative(root);
    }
};
