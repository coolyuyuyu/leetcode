/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root, vector<vector<int>>& ret) {
        int h = 0;
        if (root){
            h = max(height(root->left, ret), height(root->right, ret)) + 1;

            while (ret.size() < h) {
                ret.push_back(vector<int>());
            }
            ret[h - 1].push_back(root->val);
        }
        return h;
    }

    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ret;
        height(root, ret);
        return ret;
    }
};