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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> pairs;
        if (root) {
            pairs.push(pair<TreeNode*, int>(root, 0));
        }

        int maxWidth = 0;
        while (!pairs.empty()) {
            if (pairs.size() == 1) {
                maxWidth = max(maxWidth, 1);
            }
            else {
                maxWidth = max(maxWidth, pairs.back().second - pairs.front().second + 1);
            }

            for (size_t n = pairs.size(); n > 0; --n) {
                const pair<TreeNode*, int>& p = pairs.front();
                TreeNode* node = p.first;
                int index = p.second;

                TreeNode* lft = node->left;
                if (lft) {
                    pairs.push(pair<TreeNode*, int>(lft, index * 2));
                }

                TreeNode* rht = node->right;
                if (rht) {
                    pairs.push(pair<TreeNode*, int>(rht, index * 2 + 1));
                }
                pairs.pop();
            }
        }


        return maxWidth;
    }
};