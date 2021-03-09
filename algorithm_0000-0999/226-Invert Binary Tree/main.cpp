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
    void invertTree_Recursive(TreeNode* root) {
        if (root) {
            swap(root->left, root->right);
            invertTree_Recursive(root->left);
            invertTree_Recursive(root->right);
        }
    }

    void invertTree_Iterative(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }
        while (!q.empty()) {
            for (size_t i = q.size(); 0 < i; --i) {
                root = q.front();
                q.pop();

                swap(root->left, root->right);

                if (root->left) {
                    q.push(root->left);
                }
                if (root->right) {
                    q.push(root->right);
                }
            }
        }
    }

    TreeNode* invertTree(TreeNode* root) {
        //invertTree_Recursive(root);
        invertTree_Iterative(root);

        return root;
    }
};