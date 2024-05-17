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
    TreeNode* recursive(TreeNode* root, int target) {
        if (!root) { return nullptr; }

        root->left = recursive(root->left, target);
        root->right = recursive(root->right, target);
        if (!root->left && !root->right && root->val == target) {
            return nullptr;
        }
        else {
            return root;
        }
    }

    TreeNode* iterative(TreeNode* root, int target) {
        stack<pair<TreeNode**, bool>> stk({{&root, false}});
        while (!stk.empty()) {
            auto [ppNode, visited] = stk.top();
            stk.pop();

            if (*ppNode == nullptr) { continue; }

            if (visited) {
                if ((*ppNode)->left == nullptr && (*ppNode)->right == nullptr && (*ppNode)->val == target) {
                    *ppNode = nullptr;
                }
            }
            else {
                stk.emplace(ppNode, true);
                stk.emplace(&((*ppNode)->right), false);
                stk.emplace(&((*ppNode)->left), false);
            }
        }

        return root;
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        //return recursive(root, target);
        return iterative(root, target);
    }
};
