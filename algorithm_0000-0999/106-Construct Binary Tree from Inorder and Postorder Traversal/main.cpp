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
    TreeNode* recursive(const vector<int>& inorder, size_t inIdx, const vector<int>& postorder, size_t postIdx, size_t size, unordered_map<int, size_t>& inIndexes) {
        if (size == 0) {
            return nullptr;
        }

        int val = postorder[postIdx + size - 1];
        size_t lftSize = (inIndexes[val] - inIdx);
        size_t rhtSize = size - 1 - lftSize;
        return new TreeNode(
            val,
            recursive(inorder, inIdx, postorder, postIdx, lftSize, inIndexes),
            recursive(inorder, inIdx + lftSize + 1, postorder, postIdx + lftSize, rhtSize, inIndexes));
    }

    TreeNode* iterative(const vector<int>& inorder, const vector<int>& postorder, unordered_map<int, size_t>& inIndexes) {
        TreeNode* root = nullptr;
        stack<tuple<TreeNode**, size_t, size_t, size_t>> stk({{&root, 0, 0, inorder.size()}});
        while (!stk.empty()) {
            auto [ppNode, inIdx, postIdx, size] = stk.top();
            stk.pop();

            if (size == 0) {
                *ppNode = nullptr;
                continue;
            }

            int val = postorder[postIdx + size - 1];
            size_t lftSize = (inIndexes[val] - inIdx);
            size_t rhtSize = size - 1 - lftSize;
            *ppNode = new TreeNode(val);

            stk.emplace(&((*ppNode)->left), inIdx, postIdx, lftSize);
            stk.emplace(&((*ppNode)->right), inIdx + lftSize + 1, postIdx + lftSize, rhtSize);
        }
        
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        size_t n = inorder.size();
        unordered_map<int, size_t> inIndexes;
        for (size_t i = 0; i < n; ++i) {
            inIndexes[inorder[i]] = i;
        }
        
        //return recursive(inorder, 0, postorder, 0, n, inIndexes);
        return iterative(inorder, postorder, inIndexes);
    }
};
