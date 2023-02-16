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
        if (!root) {
            return 0;
        }

        return 1 + std::max(recursive(root->left), recursive(root->right));
    }

    int iterative(TreeNode* root) {
        queue<TreeNode*> q({root});
        int d = -1;
        for (; !q.empty(); ++d) {
            for (int i = q.size(); 0 < i--;) {
                root = q.front();
                q.pop();

                if (!root) {
                    continue;
                }

                q.push(root->left);
                q.push(root->right);
            }
        }
        
        return d;
    }

    int maxDepth(TreeNode* root) {
        return recursive(root);
        //return iterative(root);
    }
};
