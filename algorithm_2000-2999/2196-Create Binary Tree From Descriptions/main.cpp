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
            int p = description[0], c = description[1], l = description[2];

            if (nodes.find(p) == nodes.end()) {
                nodes[p] = new TreeNode(p);
            }
            TreeNode* parent = nodes[p];

            if (nodes.find(c) == nodes.end()) {
                nodes[c] = new TreeNode(c);
            }
            TreeNode* child = nodes[c];

            if (l) {
                parent->left = child;
            }
            else {
                parent->right = child;
            }
        }

        int rootVal = 0;
        for (const auto& [_, node] : nodes) {
            rootVal ^= node->val;
            if (node->left) {
                rootVal ^= node->left->val;
            }
            if (node->right) {
                rootVal ^= node->right->val;
            }
        }

        TreeNode* root;
        for (const auto& [_, node] : nodes) {
            if (node->val == rootVal) {
                root = node;
                break;
            }
        }

        return root;
    }
};
