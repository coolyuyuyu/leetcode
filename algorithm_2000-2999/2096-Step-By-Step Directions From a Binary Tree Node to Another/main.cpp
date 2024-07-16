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
    bool dfs(TreeNode* root, int target, string& dirs) {
        if (!root) { return false; }
        if (root->val == target) {
            return true;
        }

        dirs.push_back('L');
        if (dfs(root->left, target, dirs)) {
            return true;
        }
        dirs.pop_back();

        dirs.push_back('R');
        if(dfs(root->right, target, dirs)) {
            return true;
        }
        dirs.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string dirs1, dirs2;
        dfs(root, startValue, dirs1);
        dfs(root, destValue, dirs2);

        int k = 0;
        while (k < dirs1.size() && k < dirs2.size() && dirs1[k] == dirs2[k]) {
            ++k;
        }

        string ret;
        for (int i = k; i < dirs1.size(); ++i) {
            ret.push_back('U');
        }
        for (int j = k; j < dirs2.size(); ++j) {
            ret.push_back(dirs2[j]);
        }

        return ret;
    }
};
