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
    int pseudoPalindromicPaths_Recursive(TreeNode* root, bitset<10> flags = bitset<10>()) {
        if (!root) {
            return 0;
        }

        flags[root->val].flip();
        if (!root->left && !root->right) {
            return (flags.count() <= 1 ? 1 : 0);
        }
        else {
            return pseudoPalindromicPaths_Recursive(root->left, flags) + pseudoPalindromicPaths_Recursive(root->right, flags);
        }
    }

    int pseudoPalindromicPaths_Iterative(TreeNode* root) {
        int numPaths = 0;
        bitset<10> flags(0);

        stack<pair<TreeNode*, bool>> stk({{root, false}});
        while (!stk.empty()) {
            TreeNode* node = stk.top().first;
            bool visited = stk.top().second;
            stk.pop();

            if (visited) {
                flags[node->val].flip();
            }
            else {
                flags[node->val].flip();
                if (!node->left && !node->right) {
                    if (flags.count() <= 1) {
                        ++numPaths;
                    }
                }

                stk.emplace(node, true);
                if (node->right) {
                    stk.emplace(node->right, false);
                }
                if (node->left) {
                    stk.emplace(node->left, false);
                }
            }
        }

        return numPaths;
    }

    int pseudoPalindromicPaths(TreeNode* root) {
        //return pseudoPalindromicPaths_Recursive(root);
        return pseudoPalindromicPaths_Iterative(root);
    }
};