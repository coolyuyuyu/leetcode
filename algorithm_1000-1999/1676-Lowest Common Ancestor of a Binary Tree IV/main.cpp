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
    TreeNode* lowestCommonAncestor_Recursive(TreeNode* root, const set<TreeNode*>& nodes) {
        if (!root || nodes.find(root) != nodes.end()) {
            return root;
        }
        else {
            TreeNode* lftLCA = lowestCommonAncestor_Recursive(root->left, nodes);
            TreeNode* rhtLCA = lowestCommonAncestor_Recursive(root->right, nodes);
            if (lftLCA && rhtLCA) {
                return root;
            }
            else {
                return (lftLCA ? lftLCA : rhtLCA);
            }
        }
    }

    TreeNode* lowestCommonAncestor_Iterative(TreeNode* root, const set<TreeNode*>& nodes) {
        map<TreeNode*, TreeNode*> m; // <node, lca>
        // postorder traversal
        stack<pair<TreeNode*, bool>> stk;
        stk.emplace(root, false);
        while (!stk.empty()) {
            TreeNode* node = stk.top().first;
            if (stk.top().second) {
                stk.pop();

                TreeNode* lftLCA = (node->left ? m[node->left] : nullptr);
                TreeNode* rhtLCA = (node->right ? m[node->right] : nullptr);
                if (lftLCA && rhtLCA) {
                    m[node] = node;
                }
                else {
                    m[node] = (lftLCA ? lftLCA : rhtLCA);
                }
            }
            else {
                if (nodes.find(node) != nodes.end()) {
                    m[node] = node;

                    stk.pop();
                    continue;
                }
                else {
                    stk.top().second = true;
                }

                if (node->right) {
                    stk.emplace(node->right, false);
                }
                if (node->left) {
                    stk.emplace(node->left, false);
                }
            }
        }

        return m[root];
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*>& nodes) {
        //return lowestCommonAncestor_Recursive(root, set<TreeNode*>(nodes.begin(), nodes.end()));
        return lowestCommonAncestor_Iterative(root, set<TreeNode*>(nodes.begin(), nodes.end()));
    }
};