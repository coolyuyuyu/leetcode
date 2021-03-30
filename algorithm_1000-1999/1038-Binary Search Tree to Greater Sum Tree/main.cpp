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
    void bstToGst_Recursive(TreeNode* root, int& sum) {
        if (!root) {
            return;
        }

        bstToGst_Recursive(root->right, sum);

        int tmp = root->val;
        root->val += sum;
        sum += tmp;

        bstToGst_Recursive(root->left, sum);
    }

    void bstToGst_Iterative(TreeNode* root, int& sum) {
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
                int tmp = node->val;
                node->val += sum;
                sum += tmp;
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

    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;

        //bstToGst_Recursive(root, sum);
        bstToGst_Iterative(root, sum);

        return root;
    }
};