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
    int height(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return max(height(root->left), height(root->right)) + 1;
    }

    TreeNode* subtreeWithAllDeepest_Recursive(TreeNode* root, int height, int depth = 0) {
        if (!root) {
            return nullptr;
        }

        ++depth;
        if (height <= depth) {
            return root;
        }

        TreeNode* lft = subtreeWithAllDeepest_Recursive(root->left, height, depth);
        TreeNode* rht = subtreeWithAllDeepest_Recursive(root->right, height, depth);
        if (lft && rht) {
            return root;
        }
        else {
            return (lft ? lft : rht);
        }
    }

    TreeNode* subtreeWithAllDeepest_Iterative(TreeNode* root, int height) {
        map<TreeNode*, TreeNode*> m; // <node, lowest_common_ancestor>

        // postorder traversal
        stack<tuple<TreeNode*, int, bool>> stk; // <node, depth, visited>
        if (root) {
            stk.emplace(root, 1, false);
        }
        while (!stk.empty()) {
            TreeNode* node = get<0>(stk.top());
            int depth = get<1>(stk.top());
            bool visited = get<2>(stk.top());
            stk.pop();

            if (visited) {
                if (height <= depth) {
                    m[node] = node;
                }
                else {
                    TreeNode* lftLCA = (node->left ? m[node->left] : nullptr);
                    TreeNode* rhtLCA = (node->right ? m[node->right] : nullptr);
                    if (lftLCA && rhtLCA) {
                        m[node] = node;
                    }
                    else {
                        m[node] = (lftLCA ? lftLCA : rhtLCA);
                    }
                }
            }
            else {
                stk.emplace(node, depth, true);
                if (node->right) {
                    stk.emplace(node->right, depth + 1, false);
                }
                if (node->left) {
                    stk.emplace(node->left, depth + 1, false);
                }
            }
        }

        return m[root];
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int h = height(root);

        //return subtreeWithAllDeepest_Recursive(root, h);
        return subtreeWithAllDeepest_Iterative(root, h);
    }
};