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
    // Time: O(k)
    int kthSmallest_Recursive(TreeNode* root, int& k) {
        if (!root) {
            return 0;
        }

        int num = kthSmallest_Recursive(root->left, k);
        if (k == 0) {
            return num;
        }
        else {
            if (--k == 0) {
                return root->val;
            }
            else {
                return kthSmallest_Recursive(root->right, k);
            }
        }
    }

    // Time: O(k)
    int kthSmallest_Iterative(TreeNode* root, int k) {
        stack<pair<TreeNode*, bool>> stk;
        if (root) {
            stk.emplace(root, false);
        }
        while (!stk.empty()) {
            TreeNode* node = stk.top().first;
            bool visited = stk.top().second;
            stk.pop();

            if (visited) {
                if (--k == 0) {
                    return node->val;
                }
            }
            else {
                if (node->right) {
                    stk.emplace(node->right, false);
                }
                stk.emplace(node, true);
                if (node->left) {
                    stk.emplace(node->left, false);
                }
            }
        }

        assert(false);
        return -1;
    }

    int kthSmallest(TreeNode* root, int k) {
        //return kthSmallest_Recursive(root, k);
        return kthSmallest_Iterative(root, k);
    }
};