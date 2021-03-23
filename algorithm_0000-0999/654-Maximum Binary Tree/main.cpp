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
    TreeNode* constructMaximumBinaryTree_Recursive(vector<int>::iterator first, vector<int>::iterator last) {
        assert(first <= last);
        if (first == last) {
            return nullptr;
        }

        vector<int>::iterator mid = max_element(first, last);
        TreeNode* root = new TreeNode(*mid);
        root->left = constructMaximumBinaryTree_Recursive(first, mid);
        root->right = constructMaximumBinaryTree_Recursive(mid + 1, last);
        return root;
    }

    TreeNode* constructMaximumBinaryTree_Iterative(vector<int>::iterator first, vector<int>::iterator last) {
        TreeNode* pRoot = nullptr;

        stack<pair<TreeNode**, pair<vector<int>::iterator, vector<int>::iterator>>> stk({{&pRoot, make_pair(first, last)}});
        while (!stk.empty()) {
            TreeNode** ppNode = stk.top().first;
            auto range = stk.top().second;
            stk.pop();

            if (range.second <= range.first) {
                continue;
            }
            auto mid = max_element(range.first, range.second);
            *ppNode = new TreeNode(*mid);

            stk.emplace(&((*ppNode)->left), make_pair(range.first, mid));
            stk.emplace(&((*ppNode)->right), make_pair(mid + 1, range.second));
        }

        return pRoot;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        //return constructMaximumBinaryTree_Recursive(nums.begin(), nums.end());
        return constructMaximumBinaryTree_Iterative(nums.begin(), nums.end());
    }
};