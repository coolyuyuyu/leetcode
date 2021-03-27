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
    bool buildBackEdgesFromTarget2Root(TreeNode* root, TreeNode* target, unordered_map<TreeNode*, TreeNode*>& backEdges) {
        if (!root) {
            return false;
        }
        else if (root == target) {
            return true;
        }

        if (buildBackEdgesFromTarget2Root(root->left, target, backEdges)) {
            backEdges.emplace(root->left, root);
            return true;
        }

        if (buildBackEdgesFromTarget2Root(root->right, target, backEdges)) {
            backEdges.emplace(root->right, root);
            return true;
        }

        return false;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*, TreeNode*> backEdges;
        buildBackEdgesFromTarget2Root(root, target, backEdges);

        // bfs
        queue<TreeNode*> candidates({target});
        unordered_set<TreeNode*> visited({target});
        while (!candidates.empty() && 0 < K--) {
            for (size_t i = candidates.size(); 0 < i; --i) {
                TreeNode* node = candidates.front();
                candidates.pop();

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
        }

        vector<int> ret;
        while (!candidates.empty()) {
            ret.push_back(candidates.front()->val);
            candidates.pop();
        }
        return ret;
    }
};