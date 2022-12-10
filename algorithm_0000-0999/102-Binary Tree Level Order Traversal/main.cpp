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
    void recursive(TreeNode* root, int depth, vector<vector<int>>& ans) {
        if (!root) {
            return;
        }

        if (ans.size() <= depth) {
            ans.resize(depth + 1);
        }
        ans[depth].push_back(root->val);
        recursive(root->left, depth + 1, ans);
        recursive(root->right, depth + 1, ans);
    }

    vector<vector<int>> recursive(TreeNode* root) {
        vector<vector<int>> ans;
        recursive(root, 0, ans);
        return ans;
    }

    vector<vector<int>> iterative(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }

        vector<vector<int>> ans;
        while (!q.empty()) {
            ans.emplace_back();
            for (size_t i = 0, n = q.size(); i < n; ++i) {
                root = q.front();
                q.pop();

                ans.back().push_back(root->val);
                if (root->left) {
                    q.push(root->left);
                }
                if (root->right) {
                    q.push(root->right);
                }
            }
        }

        return ans;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        //return recursive(root);
        return iterative(root);
    }
};
