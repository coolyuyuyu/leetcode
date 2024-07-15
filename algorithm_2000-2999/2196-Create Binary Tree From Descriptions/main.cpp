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

            if (nodes.find(parentVal) == nodes.end()) {
                nodes[parentVal] = new TreeNode(parentVal);
            }
            TreeNode* parent = nodes[parentVal];
            if (nodes.find(childVal) == nodes.end()) {
                nodes[childVal] = new TreeNode(childVal);
            }
            TreeNode* child = nodes[childVal];

            TreeNode** ppChild = &(isLeft ? parent->left: parent->right);
            *ppChild = child;
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
