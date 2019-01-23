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
    bool search(TreeNode* node, TreeNode* parent, TreeNode* target, unordered_map<TreeNode*, TreeNode*>& backEdges) {
        assert(target);

        if (!node) {
            return false;
        }

        if (node == target) {
            if (parent) {
                backEdges.emplace(node, parent);
            }
            return true;
        }

        bool foundLft = search(node->left, node, target, backEdges);
        if (foundLft) {
            if (parent) {
                backEdges.emplace(node, parent);
            }
            return true;
        }
        else {
            bool foundRht = search(node->right, node, target, backEdges);
            if (foundRht) {
                if (parent) {
                    backEdges.emplace(node, parent);
                }
            }
            return foundRht;
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*, TreeNode*> backEdges;
        search(root, nullptr, target, backEdges);

        queue<TreeNode*> q;
        q.emplace(target);
        unordered_set<TreeNode*> seen;
        while (0 < K--) {
            size_t n = q.size();
            for (size_t i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();

                if (seen.emplace(node).second == false) {
                    continue;
                }

                if (node->left && seen.find(node->left) == seen.end()) {
                    q.emplace(node->left);
                }

                if (node->right && seen.find(node->right) == seen.end()) {
                    q.emplace(node->right);
                }

                if (backEdges.find(node) != backEdges.end() && seen.find(backEdges[node]) == seen.end()) {
                    q.emplace(backEdges[node]);
                }
            }
        }

        vector<int> nums(q.size());
        for (size_t i = 0; i < nums.size(); ++i) {
            nums[i] = q.front()->val;
            q.pop();
        }
        return nums;
    }
};