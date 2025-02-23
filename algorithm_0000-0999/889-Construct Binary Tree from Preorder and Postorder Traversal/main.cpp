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
    TreeNode* recursive(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        unordered_map<int, int> val2postidx;
        for (int i = 0; i < n; ++i) {
            val2postidx[postorder[i]] = i;
        }
        std::function<TreeNode*(int, int, int)> f = [&](int size, int i, int j) {
            if (size == 0) { return (TreeNode*)nullptr; }

            TreeNode* root = new TreeNode(preorder[i]);
            int lftSize = size > 1 ? (val2postidx[preorder[i + 1]] - j + 1) : 0;
            int rhtSize = size - lftSize - 1;
            root->left = f(lftSize, i + 1, j);
            root->right = f(rhtSize, i + 1 + lftSize, j + lftSize);

            return root;
        };

        return f(n, 0, 0);
    }

    TreeNode* iterative(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        unordered_map<int, int> val2postidx;
        for (int i = 0; i < n; ++i) {
            val2postidx[postorder[i]] = i;
        }

        TreeNode* root = nullptr;
        stack<tuple<TreeNode**, int, int, int>> stk({{&root, n, 0, 0}});
        while (!stk.empty()) {
            auto [ppNode, size, i, j] = stk.top();
            stk.pop();

            if (size == 0) {
                continue;
            }

            *ppNode = new TreeNode(preorder[i]);
            int lftSize = size > 1 ? (val2postidx[preorder[i + 1]] - j + 1) : 0;
            int rhtSize = size - lftSize - 1;
            stk.emplace(&((*ppNode)->left), lftSize, i + 1, j);
            stk.emplace(&((*ppNode)->right), rhtSize, i + 1 + lftSize, j + lftSize);
        }

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        //return recursive(preorder, postorder);
        return iterative(preorder, postorder);
    }
};
