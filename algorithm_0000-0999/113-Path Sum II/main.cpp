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
    void pathSum_Recursive(TreeNode* root, int remaining, vector<int>& path, vector<vector<int>>& paths) {
        if (!root) {
            return;
        }

        path.push_back(root->val);
        if (!root->left && !root->right && root->val == remaining) {
            paths.push_back(path);
        }
        pathSum_Recursive(root->left, remaining - root->val, path, paths);
        pathSum_Recursive(root->right, remaining - root->val, path, paths);
        path.pop_back();
    }

    void pathSum_Iterative(TreeNode* root, int remaining, vector<int>& path, vector<vector<int>>& paths) {
        // preorder traversal
        stack<pair<TreeNode*, bool>> stk;
        if (root) {
            stk.emplace(root, false);
        }
        while (!stk.empty()) {
            TreeNode* node = stk.top().first;
            bool visited = stk.top().second;
            stk.pop();

            if (visited) {
                remaining += path.back();
                path.pop_back();
            }
            else {
                remaining -= node->val;
                path.push_back(node->val);

                stk.emplace(node, true);
                if (!node->left && !node->right) {
                    if (remaining == 0) {
                        paths.push_back(path);
                    }
                }
                else {
                    if (node->right) {
                        stk.emplace(node->right, false);
                    }
                    if (node->left) {
                        stk.emplace(node->left, false);
                    }
                }
            }
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        vector<vector<int>> paths;

        //pathSum_Recursive(root, targetSum, path, paths);
        pathSum_Iterative(root, targetSum, path, paths);

        return paths;
    }
};