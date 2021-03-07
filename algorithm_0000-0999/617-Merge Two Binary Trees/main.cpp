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
    TreeNode* mergeTrees_Recursive(TreeNode* root1, TreeNode* root2) {
        if (!root1) {
            return root2;
        }
        if (!root2) {
            return root1;
        }

        root1->val += root2->val;
        root1->left = mergeTrees_Recursive(root1->left, root2->left);
        root1->right = mergeTrees_Recursive(root1->right, root2->right);
        return root1;
    }

    TreeNode* mergeTrees_Iterative(TreeNode* root1, TreeNode* root2) {
        if (!root1) {
            return root2;
        }
        if (!root2) {
            return root1;
        }
        assert(root1 && root2);

        stack<pair<TreeNode*, TreeNode*>> stk;
        stk.emplace(root1, root2);
        while (!stk.empty()) {
            TreeNode* node1 = stk.top().first;
            TreeNode* node2 = stk.top().second;
            stk.pop();

            node1->val += node2->val;

            if (!node1->right) {
                swap(node1->right, node2->right);
            }
            if (node1->right && node2->right) {
                stk.emplace(node1->right, node2->right);
            }

            if (!node1->left) {
                swap(node1->left, node2->left);
            }
            if (node1->left && node2->left) {
                stk.emplace(node1->left, node2->left);
            }
        }

        return root1;
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        //return mergeTrees_Recursive(root1, root2);
        return mergeTrees_Iterative(root1, root2);
    }
};