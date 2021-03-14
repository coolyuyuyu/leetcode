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
    TreeNode* cloneTree(TreeNode* root, int diff) {
        if (!root) {
            return nullptr;
        }
        return new TreeNode(root->val + diff, cloneTree(root->left, diff), cloneTree(root->right, diff));
    }

    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode*>> trees = {{nullptr}};
        for (int i = 1; i <= n; ++i) {
            trees.push_back({});
            for (int j = 0; j < i; ++j) {
                for (TreeNode* lft : trees[j]) {
                    for (TreeNode* rht : trees[i - j - 1]) {
                        TreeNode* root = new TreeNode(j + 1, lft, cloneTree(rht, j + 1));
                        trees[i].push_back(root);
                    }
                }
            }
        }

        return trees[n];
    }
};
