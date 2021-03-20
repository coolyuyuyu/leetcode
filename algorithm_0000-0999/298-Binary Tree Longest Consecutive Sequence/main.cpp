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
    int longestConsecutive_Recursive(TreeNode* root, int& maxLcs) {
        if (!root) {
            return 0;
        }

        int lcs = 1;
        int lftLcs = longestConsecutive_Recursive(root->left, maxLcs);
        int rhtLcs = longestConsecutive_Recursive(root->right, maxLcs);
        if (root->left && (root->val + 1) == root->left->val) {
            lcs = max(lcs, lftLcs + 1);
        }
        if (root->right && (root->val + 1) == root->right->val) {
            lcs = max(lcs, rhtLcs + 1);
        }

        if (maxLcs < lcs) {
            maxLcs = lcs;
        }

        return lcs;
    }

    int longestConsecutive_Iterative(TreeNode* root) {
        int maxLcs = 0;

        map<TreeNode*, int> m; // <node, lcs>
        stack<pair<TreeNode*, bool>> stk; // <node, visited>
        if (root) {
            stk.emplace(root, false);
        }
        while (!stk.empty()) {
            TreeNode* node = stk.top().first;
            bool visited = stk.top().second;
            stk.pop();

            if (visited) {
                int lcs = 1;
                if (node->left && (node->val + 1) == node->left->val) {
                    lcs = m[node->left] + 1;
                }
                if (node->right && (node->val + 1) == node->right->val) {
                    lcs = max(lcs, m[node->right] + 1);
                }
                if (maxLcs < lcs) {
                    maxLcs = lcs;
                }
                m[node] = lcs;
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

        return maxLcs;
    }

    int longestConsecutive(TreeNode* root) {
        //int maxLcs = 0;
        //longestConsecutive_Recursive(root, maxLcs);
        //return maxLcs;

        return longestConsecutive_Iterative(root);
    }
};