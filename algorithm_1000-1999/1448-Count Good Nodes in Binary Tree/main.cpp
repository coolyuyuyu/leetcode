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
    int goodNodes_Recursive(TreeNode* root, int* pMaxVal = nullptr) {
        if (!root) {
            return 0;
        }

        if (!pMaxVal) {
            pMaxVal = &(root->val);
        }

        int count = 0;
        if (*pMaxVal <= root->val) {
            ++count;
            pMaxVal = &(root->val);
        }
        count += goodNodes_Recursive(root->left, pMaxVal);
        count += goodNodes_Recursive(root->right, pMaxVal);

        return count;
    }

    int goodNodes_Iterative(TreeNode* root) {
        int count = 0;

        stack<pair<TreeNode*, int>> stk({{root, root->val}});
        while (!stk.empty()) {
            TreeNode* node = stk.top().first;
            int maxVal = stk.top().second;
            stk.pop();

            if (maxVal <= node->val) {
                ++count;
                maxVal = node->val;
            }

            if (node->right) {
                stk.emplace(node->right, maxVal);
            }
            if (node->left) {
                stk.emplace(node->left, maxVal);
            }
        }

        return count;
    }

    int goodNodes(TreeNode* root) {
        //return goodNodes_Recursive(root);
        return goodNodes_Iterative(root);
    }
};