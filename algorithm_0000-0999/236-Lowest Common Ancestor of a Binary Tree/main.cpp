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
    TreeNode* lowestCommonAncestor_Recursive(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) {
            return root;
        }
        else {
            TreeNode* lftLCA = lowestCommonAncestor_Recursive(root->left, p, q);
            TreeNode* rhtLCA = lowestCommonAncestor_Recursive(root->right, p, q);
            if (lftLCA && rhtLCA) {
                return root;
            }
            else {
                return lftLCA ? lftLCA : rhtLCA;
            }
        }
    }

    TreeNode* lowestCommonAncestor_Iterative(TreeNode* root, TreeNode* p, TreeNode* q) {
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
                if (node == p || node == q) {
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

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //return lowestCommonAncestor_Recursive(root, p, q);
        return lowestCommonAncestor_Iterative(root, p, q);
    }
};