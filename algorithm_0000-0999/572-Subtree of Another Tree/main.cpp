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
    bool isSame_recv(TreeNode* root1, TreeNode* root2) {
        return (root1 == root2) || (root1 && root2 && root1->val == root2->val && isSame_recv(root1->left, root2->left) && isSame_recv(root1->right, root2->right));
    }

    // Time: O(MN)
    bool dfs_recv(TreeNode* root, TreeNode* subRoot) {
        return isSame_recv(root, subRoot) || (root && (dfs_recv(root->left, subRoot) || dfs_recv(root->right, subRoot)));
    }

    bool isSame_iter(TreeNode* root1, TreeNode* root2) {
        stack<pair<TreeNode*, TreeNode*>> stk({{root1, root2}});
        while (!stk.empty()) {
            auto [root1, root2] = stk.top();
            stk.pop();

            if (root1 == root2) {
                continue;
            }
            if (!root1 || !root2 || root1->val != root2->val) {
                return false;
            }

            stk.emplace(root1->left, root2->left);
            stk.emplace(root1->right, root2->right);
        }

        return true;
    }

    // Time: O(MN)
    bool dfs_iter(TreeNode* root, TreeNode* subRoot) {
        stack<TreeNode*> stk({root});
        while (!stk.empty()) {
            auto root = stk.top();
            stk.pop();

            if (isSame_iter(root, subRoot)) {
                return true;
            }

            if (root->left) {
                stk.push(root->left);
            }
            if (root->right) {
                stk.push(root->right);
            }
        }

        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs_recv(root, subRoot);
        //return dfs_iter(root, subRoot);
    }
};
