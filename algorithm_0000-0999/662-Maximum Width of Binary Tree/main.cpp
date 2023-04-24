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
        assert(root);

        int width = 0;
        queue<pair<TreeNode*, size_t>> q({{root, 0}});
        while (!q.empty()) {
            width = std::max<int>(width, q.back().second - q.front().second + 1);
            for (int n = q.size(); 0 < n--;) {
                auto [node, id] = q.front();;
                q.pop();

                if (node->left) {
                    q.emplace(node->left, id * 2 + 1);
                }
                if (node->right) {
                    q.emplace(node->right, id * 2 + 2);
                }
            }
        }

        return width;
    }

    int widthOfBinaryTree(TreeNode* root) {
        //vector<pair<size_t, size_t>> ranges;
        //int width = 0;
        //widthOfBinaryTree_Recursive(root, 0, 1, ranges, width);
        //return width;

        return widthOfBinaryTree_Iterative(root);
    }
};
