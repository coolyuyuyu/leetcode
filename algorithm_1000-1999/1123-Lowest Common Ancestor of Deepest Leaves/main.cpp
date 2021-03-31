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
    pair<int, TreeNode*> lcaDeepestLeaves_Recursive(TreeNode* root, int depth = 0) {
        if (!root) {
            return {depth, nullptr};
        }

        pair<int, TreeNode*> lft = lcaDeepestLeaves_Recursive(root->left, depth + 1);
        pair<int, TreeNode*> rht = lcaDeepestLeaves_Recursive(root->right, depth + 1);
        if (lft.first == rht.first) {
            return {rht.first, root};
        }
        else if (lft.first < rht.first){
            return rht;
        }
        else {
            return lft;
        }
    }

    pair<int, TreeNode*> lcaDeepestLeaves_Iterative(TreeNode* root) {
        unordered_map<TreeNode*, pair<int, TreeNode*>> m; // <node, <depth, lca>>

        // postorder traversal
        stack<pair<pair<int, TreeNode*>, bool>> stk; // <<depth, node>, visited>
        if (root) {
            stk.emplace(make_pair(1, root), false);
        }
        while (!stk.empty()) {
            int depth = stk.top().first.first;
            TreeNode* node = stk.top().first.second;
            bool visited = stk.top().second;
            stk.pop();

            if (visited) {
                pair<int, TreeNode*> lft = (node->left ? m[node->left] : make_pair(depth + 1, nullptr));
                pair<int, TreeNode*> rht = (node->right ? m[node->right] : make_pair(depth + 1, nullptr));
                if (lft.first == rht.first) {
                    m[node] = {rht.first, node};
                }
                else if (lft.first < rht.first){
                    m[node] = rht;
                }
                else {
                    m[node] = lft;
                }
            }
            else {
                stk.emplace(make_pair(depth, node), true);
                if (node->right) {
                    stk.emplace(make_pair(depth + 1, node->right), false);
                }
                if (node->left) {
                    stk.emplace(make_pair(depth + 1, node->left), false);
                }
            }
        }

        return m[root];
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        //return lcaDeepestLeaves_Recursive(root).second;
        return lcaDeepestLeaves_Iterative(root).second;
    }
};