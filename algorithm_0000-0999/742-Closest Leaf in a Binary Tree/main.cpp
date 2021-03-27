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
    TreeNode* buildBackEdgesFromTarget2Root(TreeNode* root, int k, unordered_map<TreeNode*, TreeNode*>& backEdges) {
        if (!root || root->val == k) {
            return root;
        }

        TreeNode* target = nullptr;
        if ((target = buildBackEdgesFromTarget2Root(root->left, k, backEdges))) {
            backEdges.emplace(root->left, root);
            return target;
        }

        if ((target = buildBackEdgesFromTarget2Root(root->right, k, backEdges))) {
            backEdges.emplace(root->right, root);
            return target;
        }

        return nullptr;
    }

    int findClosestLeaf(TreeNode* root, int k) {
        unordered_map<TreeNode*, TreeNode*> backEdges;
        TreeNode* source = buildBackEdgesFromTarget2Root(root, k, backEdges);

        // bfs
        queue<TreeNode*> candidates({source});
        unordered_set<TreeNode*> visited({source});
        while (!candidates.empty()) {
            TreeNode* node = candidates.front();
            candidates.pop();

            if (!node->left && !node->right) {
                return node->val;
            }

            if (node->left && visited.insert(node->left).second) {
                candidates.push(node->left);
            }

            if (node->right && visited.insert(node->right).second) {
                candidates.push(node->right);
            }

            auto backItr = backEdges.find(node);
            if (backItr != backEdges.end() && visited.insert(backItr->second).second) {
                candidates.push(backItr->second);
            }
        }

        assert(false);
        return -1;
    }
};