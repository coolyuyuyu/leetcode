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
    Solution()
        : m_treeVecs({{nullptr}}) {
    }

    TreeNode* cloneTree(TreeNode* root, int diff) {
        if (!root) {
            return nullptr;
        }
        return new TreeNode(root->val + diff, cloneTree(root->left, diff), cloneTree(root->right, diff));
    }

    const vector<TreeNode*>& generateTrees_Recursive(int n) {
        if (n < m_treeVecs.size()) {
            return m_treeVecs[n];
        }

        vector<TreeNode*> trees;
        for (int i = 0; i < n; ++i) {
            for (TreeNode* lft : generateTrees_Recursive(i)) {
                for (TreeNode* rht : generateTrees_Recursive(n - i - 1)) {
                    TreeNode* root = new TreeNode(i + 1, lft, cloneTree(rht, i + 1));
                    trees.push_back(root);
                }
            }
        }
        if (m_treeVecs.size() <= n) {
            m_treeVecs.resize(n + 1, {});
        }
        m_treeVecs[n] = trees;

        return m_treeVecs[n];
    }

    const vector<TreeNode*>& generateTrees_Iterative(int n) {
        if (n < m_treeVecs.size()) {
            return m_treeVecs[n];
        }

        for (int i = m_treeVecs.size(); i <= n; ++i) {
            vector<TreeNode*> trees;
            for (int j = 0; j < i; ++j) {
                for (TreeNode* lft : m_treeVecs[j]) {
                    for (TreeNode* rht : m_treeVecs[i - j - 1]) {
                        TreeNode* root = new TreeNode(j + 1, lft, cloneTree(rht, j + 1));
                        trees.push_back(root);
                    }
                }
            }
            m_treeVecs.push_back(trees);
        }

        return m_treeVecs[n];
    }

    const vector<TreeNode*>& generateTrees(int n) {
        //return generateTrees_Recursive(n);
        return generateTrees_Iterative(n);
    }

private:
    vector<vector<TreeNode*>> m_treeVecs;
};