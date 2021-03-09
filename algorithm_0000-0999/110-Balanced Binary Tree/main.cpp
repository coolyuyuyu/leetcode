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
        map<TreeNode*, pair<bool, int>> m;

        stack<pair<TreeNode*, bool>> stk;
        if (root) {
            stk.emplace(root, false);
        }
        while (!stk.empty()) {
            TreeNode* node = stk.top().first;
            bool visited = stk.top().second;
            stk.pop();

            if (visited) {
                pair<bool, int> pLft = node->left ? m[node->left] : make_pair(true, 0);
                pair<bool, int> pRht = node->right ? m[node->right] : make_pair(true, 0);
                if (pLft.first && pRht.first && abs(pLft.second - pRht.second) <= 1) {
                    m.emplace(node, make_pair(true, max(pLft.second, pRht.second) + 1));
                }
                else {
                    return false;
                }
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