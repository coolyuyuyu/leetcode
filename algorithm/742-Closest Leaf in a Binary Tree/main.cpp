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
    TreeNode* search(TreeNode* root, int k, unordered_map<TreeNode*, TreeNode*>& backEdges) {
        if (!root || root->val == k) {
            return root;
        }

        TreeNode* target = search(root->left, k, backEdges);
        if (target) {
            backEdges.emplace(root->left, root);
            return target;
        }

        target = search(root->right, k, backEdges);
        if (target) {
            backEdges.emplace(root->right, root);
        }

        return target;
    }

    int findClosestLeaf(TreeNode* root, int k) {
        unordered_map<TreeNode*, TreeNode*> backEdges;
        TreeNode* source = search(root, k, backEdges);
        assert(source);

        queue<TreeNode*> candidates;
        candidates.emplace(source);
        unordered_set<TreeNode*> seen;
        while (!candidates.empty()) {
            TreeNode* node = candidates.front();
            candidates.pop();

            if (seen.find(node) != seen.end()) {
                continue;
            }
            seen.insert(node);

            if (node->left == nullptr && node->right == nullptr) {
                return node->val;
            }

            if (node->left && seen.find(node->left) == seen.end()) {
                candidates.emplace(node->left);
            }

            if (node->right && seen.find(node->right) == seen.end()) {
                candidates.emplace(node->right);
            }

            if (backEdges.find(node) != backEdges.end() && seen.find(backEdges[node]) == seen.end()) {
                candidates.emplace(backEdges[node]);
            }
        }

        assert(false);
        return -1;
    }
};