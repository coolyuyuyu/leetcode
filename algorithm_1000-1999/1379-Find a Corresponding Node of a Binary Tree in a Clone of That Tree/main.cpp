/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy_Recursive(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (!original) {
            return nullptr;
        }

        if (original == target) {
            return cloned;
        }
        else {
            TreeNode* result = getTargetCopy_Recursive(original->left, cloned->left, target);
            if (result) {
                return result;
            }
            else {
                return getTargetCopy_Recursive(original->right, cloned->right, target);
            }
        }
    }

    TreeNode* getTargetCopy_Iterative(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        stack<pair<TreeNode*, TreeNode*>> stk({{original, cloned}});
        while (!stk.empty()) {
            original = stk.top().first;
            cloned = stk.top().second;
            stk.pop();

            if (original == target) {
                return cloned;
            }

            if (original->right) {
                stk.emplace(original->right, cloned->right);
            }
            if (original->left) {
                stk.emplace(original->left, cloned->left);
            }
        }

        return nullptr;
    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        //return getTargetCopy_Recursive(original, cloned, target);
        return getTargetCopy_Iterative(original, cloned, target);
    }
};