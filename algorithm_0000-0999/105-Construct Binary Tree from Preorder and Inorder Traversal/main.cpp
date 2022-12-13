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
    TreeNode* recursive(const vector<int>& preorder, size_t preIdx, const vector<int>& inorder, size_t inIdx, size_t size, const unordered_map<int, size_t>& inIndexes) {
        if (size == 0) {
            return nullptr;
        }

        int val = preorder[preIdx];
        size_t lftSize = inIndexes.at(val) - inIdx;
        size_t rhtSize = size - lftSize - 1;

        TreeNode* root = new TreeNode(val);
        root->left = recursive(preorder, preIdx + 1, inorder, inIdx, lftSize, inIndexes);
        root->right = recursive(preorder, preIdx + lftSize + 1, inorder, inIdx + lftSize + 1, rhtSize, inIndexes);
        return root;
    }

    TreeNode* iterative(const vector<int>& preorder, const vector<int>& inorder, const unordered_map<int, size_t>& inIndexes) {
        TreeNode* pRoot = nullptr;
        TreeNode** ppNode = &pRoot;
        queue<tuple<TreeNode**, size_t, size_t, size_t>> q;
        q.emplace(ppNode, 0, 0, preorder.size());

        while (!q.empty()) {
            ppNode = std::get<0>(q.front());
            size_t preIdx = std::get<1>(q.front());
            size_t inIdx = std::get<2>(q.front());
            size_t size = std::get<3>(q.front());
            q.pop();

            if (size == 0) {
                continue;
            }

            int val = preorder[preIdx];
            size_t lftSize = inIndexes.at(val) - inIdx;
            size_t rhtSize = size - lftSize - 1;

            *ppNode = new TreeNode(val);
            q.emplace(&((*ppNode)->left), preIdx + 1, inIdx, lftSize);
            q.emplace(&((*ppNode)->right), preIdx + lftSize + 1, inIdx + lftSize + 1, rhtSize);
        }

        return pRoot;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        size_t n = preorder.size();

        unordered_map<int, size_t> inIndexes;
        for (size_t i = 0; i < n; ++i) {
            inIndexes[inorder[i]] = i;
        }

        //return recursive(preorder, 0, inorder, 0, n, inIndexes);
        return iterative(preorder, inorder, inIndexes);
    }
};
