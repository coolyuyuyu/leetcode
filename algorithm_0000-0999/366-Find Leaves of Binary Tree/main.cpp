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
    int findLeaves_Recursive(TreeNode* root, vector<vector<int>>& ret) {
        if (!root) {
            return 0;
        }

        int height = max(findLeaves_Recursive(root->left, ret), findLeaves_Recursive(root->right, ret)) + 1;
        if (ret.size() <= height) {
            ret.resize(height);
        }
        ret[height - 1].push_back(root->val);

        return height;
    }

    void findLeaves_Iterative(TreeNode* root, vector<vector<int>>& ret) {
        map<TreeNode*, int> m; // <node, height>

        // postorder traversal
        stack<pair<TreeNode*, bool>> stk;
        if (root) {
            stk.emplace(root, false);
        }
        while (!stk.empty()) {
            TreeNode* node = stk.top().first;
            bool visited = stk.top().second;
            stk.pop();

            if (visited) {
                int height = max((node->left ? m[node->left] : 0), (node->right ? m[node->right] : 0)) + 1;

                if (ret.size() <= height) {
                    ret.resize(height);
                }
                ret[height - 1].push_back(node->val);

                m[node] = height;
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
    }

    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ret;

        //findLeaves_Recursive(root, ret);
        findLeaves_Iterative(root, ret);

        return ret;
    }
};