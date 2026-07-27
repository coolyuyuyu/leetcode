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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        for (const auto& description : descriptions) {
            int parentVal = description[0], childVal = description[1], isLeft = description[2];

            TreeNode*& parent = nodes[parentVal];
            if (!parent) {
                parent = new TreeNode(parentVal);
            }
            TreeNode*& child = nodes[childVal];
            if (!child) {
                child = new TreeNode(childVal);
            }
            (isLeft ? parent->left: parent->right) = child;
        }

        int rootVal = 0;
        for (const auto& [_, node] : nodes) {
            rootVal ^= node->val;
            if (node->left) { rootVal ^= node->left->val; }
            if (node->right) { rootVal ^= node->right->val; }
        }

        return nodes[rootVal];
    }
};
