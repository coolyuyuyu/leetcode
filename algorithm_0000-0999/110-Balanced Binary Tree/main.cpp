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
    bool isBalanced_Recursive(TreeNode* root, int* pDepth = nullptr) {
        if (!root) {
            if (pDepth) {
                *pDepth = 0;
            }
            return true;
        }

        int lftDepth, rhtDepth;
        if (isBalanced_Recursive(root->left, &lftDepth) && isBalanced_Recursive(root->right, &rhtDepth) && (abs(lftDepth - rhtDepth) <= 1)) {
            if (pDepth) {
                *pDepth = max(lftDepth, rhtDepth) + 1;
            }
            return true;
        }
        else {
            return false;
        }
    }

    bool isBalanced_Iterative(TreeNode* root) {
        map<TreeNode*, int> m; // <node, height>, only consists of balanced tree

        stack<pair<TreeNode*, bool>> stk;
        if (root) {
            stk.emplace(root, false);
        }
        while (!stk.empty()) {
            TreeNode* node = stk.top().first;
            bool visited = stk.top().second;
            stk.pop();

            if (visited) {
                bool lftBalanced = !node->left || m.find(node->left) != m.end();
                bool rhtBalanced = !node->right || m.find(node->right) != m.end();
                if (!lftBalanced || !rhtBalanced) {
                    return false;
                }

                int lftHeight = node->left ? m[node->left] : 0;
                int rhtHeight = node->right ? m[node->right] : 0;
                if (1 < abs(lftHeight - rhtHeight)) {
                    return false;
                }

                m.emplace(node, max(lftHeight, rhtHeight) + 1);
            }
            else {
                stk.emplace(node, true);
                if (node->right) {
                    stk.emplace(node->right, false);
                }
                if (node->left) {
                    stk.emplace(node->left, false);
                }
            }
        }

        return true;
    }

    bool isBalanced(TreeNode* root) {
        //return isBalanced_Recursive(root);
        return isBalanced_Iterative(root);
    }
};