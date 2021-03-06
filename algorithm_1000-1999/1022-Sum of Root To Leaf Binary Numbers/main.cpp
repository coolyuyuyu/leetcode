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
    void sumRootToLeaf_Recursive(TreeNode* root, int val, int& sum) {
        if (!root) {
            return;
        }

        val = val * 2 + root->val;
        if (!root->left && !root->right) {
            sum += val;
        }
        else {
            if (root->left) {
                sumRootToLeaf_Recursive(root->left, val, sum);
            }
            if (root->right) {
                sumRootToLeaf_Recursive(root->right, val, sum);
            }
        }
    }

    void sumRootToLeaf_Iterative(TreeNode* root, int& sum) {
        if (!root) {
            return;
        }

        stack<pair<TreeNode*, int>> stk;
        stk.emplace(root, root->val);
        while (!stk.empty()) {
            TreeNode* node = stk.top().first;
            int val = stk.top().second;
            stk.pop();

            if (!node->left && !node->right) {
                sum += val;
            }
            else {
                if (node->right) {
                    stk.emplace(node->right, val * 2 + node->right->val);
                }
                if (node->left) {
                    stk.emplace(node->left, val * 2 + node->left->val);
                }
            }
        }
    }

    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;

        //sumRootToLeaf_Recursive(root, 0, sum);
        sumRootToLeaf_Iterative(root, sum);

        return sum;
    }
};