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
    int diameterOfBinaryTree_Recursive(TreeNode* root, int& height) {
        if (!root) {
            height = 0;
            return 0;
        }

        int lftHeight;
        int lftDiameter = diameterOfBinaryTree_Recursive(root->left, lftHeight);
        int rhtHeight;
        int rhtDiameter = diameterOfBinaryTree_Recursive(root->right, rhtHeight);

        height = max(lftHeight, rhtHeight) + 1;
        return max(max(lftDiameter, rhtDiameter), lftHeight + rhtHeight);
    }

    int diameterOfBinaryTree_Iterative(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int diameter = 0;
        map<TreeNode*, int> m; // <node, height>

        // postorder traversal
        stack<pair<TreeNode*, bool>> stk;
        stk.emplace(root, false);
        while (!stk.empty()) {
            TreeNode* node = stk.top().first;
            if (stk.top().second) {
                stk.pop();

                int lftHeight = (node->left ? m[node->left] : 0);
                int rhtHeight = (node->right ? m[node->right] : 0);

                m[node] = max(lftHeight, rhtHeight) + 1;
                diameter = max(diameter, lftHeight + rhtHeight);
            }
            else {
                stk.top().second = true;
                if (node->right) {
                    stk.emplace(node->right, false);
                }
                if (node->left) {
                    stk.emplace(node->left, false);
                }
            }
        }

        return diameter;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        //int height;
        //return diameterOfBinaryTree_Recursive(root, height);

        return diameterOfBinaryTree_Iterative(root);
    }
};