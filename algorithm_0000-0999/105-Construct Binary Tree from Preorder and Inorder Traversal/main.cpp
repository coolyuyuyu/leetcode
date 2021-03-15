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
    TreeNode* buildTree_Recursive(vector<int>& preorder, size_t preBgn, vector<int>& inorder, size_t inBgn, size_t size, map<int, size_t>& m) {
        if (size == 0) {
            return nullptr;
        }

        int val = preorder[preBgn];
        size_t lftSize = m[val] - inBgn;
        size_t rhtSize = size - lftSize - 1;

        TreeNode* root = new TreeNode(val);
        root->left = buildTree_Recursive(preorder, preBgn + 1, inorder, inBgn, lftSize, m);
        root->right = buildTree_Recursive(preorder, preBgn + 1 + lftSize, inorder, inBgn + lftSize + 1, rhtSize, m);
        return root;
    }

    TreeNode* buildTree_Iterative(vector<int>& preorder, vector<int>& inorder, map<int, size_t>& m) {
        TreeNode* pRoot = nullptr;

        stack<pair<TreeNode**, tuple<size_t, size_t, size_t>>> stk; // <root, <preBgn, inBgn, size>>;
        if (0 < preorder.size()) {
            stk.emplace(&pRoot, make_tuple(0, 0, preorder.size()));
        }
        while (!stk.empty()) {
            TreeNode** ppNode = stk.top().first;
            size_t preBgn = get<0>(stk.top().second);
            size_t inBgn = get<1>(stk.top().second);
            size_t size = get<2>(stk.top().second);
            stk.pop();

            int val = preorder[preBgn];
            size_t lftSize = m[val] - inBgn;
            size_t rhtSize = size - lftSize - 1;

            *ppNode = new TreeNode(val);
            if (0 < lftSize) {
                stk.emplace(&((*ppNode)->left), make_tuple(preBgn + 1, inBgn, lftSize));
            }
            if (0 < rhtSize) {
                stk.emplace(&((*ppNode)->right), make_tuple(preBgn + 1 + lftSize, inBgn + lftSize + 1, rhtSize));
            }
        }

        return pRoot;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, size_t> m;
        for (size_t i = 0; i < inorder.size(); ++i) {
            m[inorder[i]] = i;
        }

        //return buildTree_Recursive(preorder, 0, inorder, 0, preorder.size(), m);
        return buildTree_Iterative(preorder, inorder, m);
    }
};