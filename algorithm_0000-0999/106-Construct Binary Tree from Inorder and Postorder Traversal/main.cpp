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
    TreeNode* buildTree_Recursive(vector<int>& inorder, size_t inBgn, vector<int>& postorder, size_t postBgn, size_t size, map<int, size_t>& m) {
        if (size == 0) {
            return nullptr;
        }

        int val = postorder[postBgn + size - 1];
        size_t lftSize = m[val] - inBgn;
        size_t rhtSize = size - lftSize - 1;

        TreeNode* root = new TreeNode(val);
        root->left = buildTree_Recursive(inorder, inBgn, postorder, postBgn, lftSize, m);
        root->right = buildTree_Recursive(inorder, inBgn + lftSize + 1, postorder, postBgn + lftSize, rhtSize, m);
        return root;
    }

    TreeNode* buildTree_Iterative(vector<int>& inorder, vector<int>& postorder, map<int, size_t>& m) {
        TreeNode* pRoot = nullptr;

        stack<pair<TreeNode**, tuple<size_t, size_t, size_t>>> stk; // <root, <inBgn, postBgn, size>>;
        if (0 < inorder.size()) {
            stk.emplace(&pRoot, make_tuple(0, 0, inorder.size()));
        }
        while (!stk.empty()) {
            TreeNode** ppNode = stk.top().first;
            size_t inBgn = get<0>(stk.top().second);
            size_t postBgn = get<1>(stk.top().second);
            size_t size = get<2>(stk.top().second);
            stk.pop();

            int val = postorder[postBgn + size - 1];
            size_t lftSize = m[val] - inBgn;
            size_t rhtSize = size - lftSize - 1;

            *ppNode = new TreeNode(val);
            if (0 < lftSize) {
                stk.emplace(&((*ppNode)->left), make_tuple(inBgn, postBgn, lftSize));
            }
            if (0 < rhtSize) {
                stk.emplace(&((*ppNode)->right), make_tuple(inBgn + lftSize + 1, postBgn + lftSize, rhtSize));
            }
        }

        return pRoot;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, size_t> m;
        for (size_t i = 0; i < inorder.size(); ++i) {
            m[inorder[i]] = i;
        }

        //return buildTree_Recursive(inorder, 0, postorder, 0, inorder.size(), m);
        return buildTree_Iterative(inorder, postorder, m);
    }
};