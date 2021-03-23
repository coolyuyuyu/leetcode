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
    void widthOfBinaryTree_Recursive(TreeNode* root, int depth, size_t index, vector<pair<size_t, size_t>>& ranges, int& maxWidth) {
        if (!root) {
            return;
        }

        if (ranges.size() <= depth) {
            ranges.emplace_back(index, index);
        }
        ranges[depth].second = index;

        int width = ranges[depth].second - ranges[depth].first + 1;
        if (maxWidth < width) {
            maxWidth = width;
        }

        widthOfBinaryTree_Recursive(root->left, depth + 1, index * 2, ranges, maxWidth);
        widthOfBinaryTree_Recursive(root->right, depth + 1, index * 2 + 1, ranges, maxWidth);
    }

    int widthOfBinaryTree_Iterative(TreeNode* root) {
        int maxWidth = 0;

        queue<pair<TreeNode*, size_t>> q;
        if (root) {
            q.emplace(root, 1);
        }
        while (!q.empty()) {
            int width = q.back().second - q.front().second + 1;
            if (maxWidth < width) {
                maxWidth = width;
            }

            for (size_t i = q.size(); 0 < i; --i) {
                TreeNode* node = q.front().first;
                size_t index = q.front().second;
                q.pop();

                if (node->left) {
                    q.emplace(node->left, index * 2);
                }
                if (node->right) {
                    q.emplace(node->right, index * 2 + 1);
                }
            }
        }

        return maxWidth;
    }

    int widthOfBinaryTree(TreeNode* root) {
        //vector<pair<size_t, size_t>> ranges;
        //int width = 0;
        //widthOfBinaryTree_Recursive(root, 0, 1, ranges, width);
        //return width;

        return widthOfBinaryTree_Iterative(root);
    }
};