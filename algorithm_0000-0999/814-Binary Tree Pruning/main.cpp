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
    TreeNode* pruneTree_Recursive(TreeNode* root) {
        if (!root) {
            return nullptr;
        }

        root->left = pruneTree_Recursive(root->left);
        root->right = pruneTree_Recursive(root->right);
        return ((!root->left && !root->right && root->val == 0) ? nullptr : root);
    }

    TreeNode* pruneTree_Iterative(TreeNode* root) {
        // postorder traversal
        stack<pair<TreeNode**, bool>> stk;
        if (root) {
            stk.emplace(&root, false);
        }
        while (!stk.empty()) {
            TreeNode** ppNode = stk.top().first;
            bool visited = stk.top().second;
            stk.pop();

            if (visited) {
                if (!((*ppNode)->left) && !((*ppNode)->right) && (*ppNode)->val == 0) {
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

    TreeNode* pruneTree(TreeNode* root) {
        //return pruneTree_Recursive(root);
        return pruneTree_Iterative(root);
    }
};