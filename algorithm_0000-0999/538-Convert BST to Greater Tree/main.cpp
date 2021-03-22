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
    void convertBST_Recursive(TreeNode* root, int& sum) {
        if (!root) {
            return;
        }

        convertBST_Recursive(root->right, sum);

        int val = root->val;
        root->val += sum;
        sum += val;

        convertBST_Recursive(root->left, sum);
    }

    void convertBST_Iterative(TreeNode* root) {
        int sum = 0;

        // reverse inorder traversal
        stack<pair<TreeNode*, bool>> stk;
        if (root) {
            stk.emplace(root, false);
        }
        while (!stk.empty()) {
            TreeNode* node = stk.top().first;
            bool visited = stk.top().second;
            stk.pop();

            if (visited) {
                int val = node->val;
                node->val += sum;
                sum += val;
            }
            else {
                if (node->left) {
                    stk.emplace(node->left, false);
                }
                stk.emplace(node, true);
                if (node->right) {
                    stk.emplace(node->right, false);
                }
            }
        }
    }

    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        convertBST_Recursive(root, sum);

        //convertBST_Iterative(root);

        return root;
    }
};