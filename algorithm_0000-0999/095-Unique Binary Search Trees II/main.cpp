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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }

        vector<vector<TreeNode*>> baseTrees = {{NULL}};
        for (int i = 1; i <= n; ++i) {
            vector<TreeNode*> trees;
            for (int j = 1; j <= i; ++j) {
                const vector<TreeNode*>& lftTrees = baseTrees[j - 1];
                const vector<TreeNode*>& rhtTrees = baseTrees[i - j];
                for (size_t x = 0; x < lftTrees.size(); ++x) {
                    for (size_t y = 0; y < rhtTrees.size(); ++y) {
                        TreeNode* root = new TreeNode(j);
                        root->left = lftTrees[x];
                        root->right = copyTree(rhtTrees[y], j);
                        trees.push_back(root);
                    }
                }

            }
            baseTrees.push_back(trees);
        }

        return baseTrees.back();
    }

    TreeNode* copyTree(TreeNode* root, int offset) {
        TreeNode* newRoot = NULL;
        if (root) {
            newRoot = new TreeNode(root->val + offset);
            newRoot->left = copyTree(root->left, offset);
            newRoot->right = copyTree(root->right, offset);
        }

        return newRoot;
    }
};
