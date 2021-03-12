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
    TreeNode* removeLeafNodes_Recursive(TreeNode* root, int target) {
        if (root->left) {
            root->left = removeLeafNodes_Recursive(root->left, target);
        }
        if (root->right) {
            root->right = removeLeafNodes_Recursive(root->right, target);
        }
        if (!root->left && !root->right && root->val == target) {
            return nullptr;
        }

        return root;
    }

    TreeNode* removeLeafNodes_Iterative(TreeNode* root, int target) {
        //postorder traversal
        stack<pair<TreeNode**, bool>> stk({{&root, false}});
        while (!stk.empty()) {
            TreeNode** ppNode = stk.top().first;
            bool visited = stk.top().second;
            stk.pop();

            if (visited) {
                if (!((*ppNode)->left) && !((*ppNode)->right) && (*ppNode)->val == target) {
                    *ppNode = nullptr;
                }
            }
            else {
                stk.emplace(ppNode, true);
                if ((*ppNode)->right) {
                    stk.emplace(&((*ppNode)->right), false);
                }
                if ((*ppNode)->left) {
                    stk.emplace(&((*ppNode)->left), false);
                }
            }
        }

        return root;
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        //return removeLeafNodes_Recursive(root, target);
        return removeLeafNodes_Iterative(root, target);
    }
};