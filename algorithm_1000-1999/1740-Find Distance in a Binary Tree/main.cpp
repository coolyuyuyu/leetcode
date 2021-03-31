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
    TreeNode* lowestCommonAncestor_Recursive(TreeNode* root, int p, int q) {
        if (!root || root->val == p || root->val == q) {
            return root;
        }

        TreeNode* lftLCA = lowestCommonAncestor_Recursive(root->left, p, q);
        TreeNode* rhtLCA = lowestCommonAncestor_Recursive(root->right, p, q);
        if (lftLCA && rhtLCA) {
            return root;
        }
        else {
            return (lftLCA ? lftLCA : rhtLCA);
        }
    }

    TreeNode* lowestCommonAncestor_Iterative(TreeNode* root, int p, int q) {
        unordered_map<TreeNode*, TreeNode*> m; // <node, lca>

        // postorder traversal
        stack<pair<TreeNode*, bool>> stk;
        if (root) {
            stk.emplace(root, false);
        }
        while (!stk.empty()) {
            TreeNode* node = stk.top().first;
            bool visited = stk.top().second;
            stk.pop();

            if (visited) {
                if (node->val == p || node->val == q) {
                    m[node] = node;
                }
                else {
                    auto itrLft = m.find(node->left), itrRht = m.find(node->right);
                    TreeNode* lftLCA = (itrLft != m.end() ? itrLft->second : nullptr);
                    TreeNode* rhtLCA = (itrRht != m.end() ? itrRht->second : nullptr);
                    TreeNode* lca = (lftLCA && rhtLCA ? node : (lftLCA ? lftLCA : rhtLCA));
                    if (lca) {
                        m[node] = lca;
                    }
                }
            }
            else {
                stk.emplace(node, true);
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

    int findDepth_Recursive(TreeNode* root, int v, int depth = 0) {
        if (!root) {
            return 0;
        }

        ++depth;
        if (root->val == v) {
            return depth;
        }
        else {
            int lftDepth = findDepth_Recursive(root->left, v, depth);
            if (0 < lftDepth) {
                return lftDepth;
            }
            else {
                return findDepth_Recursive(root->right, v, depth);
            }
        }
    }

    int findDepth_Iterative(TreeNode* root, int v) {
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }
        for (int depth = 1; !q.empty(); ++depth) {
            for (size_t i = q.size(); 0 < i; --i) {
                TreeNode* node = q.front();
                q.pop();

                if (node->val == v) {
                    return depth;
                }

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }

        return -1;
    }

    int findDistance(TreeNode* root, int p, int q) {
        //TreeNode* lca = lowestCommonAncestor_Recursive(root, p, q);
        //return (findDepth_Recursive(lca, p) + findDepth_Recursive(lca, q) - 2);

        TreeNode* lca = lowestCommonAncestor_Iterative(root, p, q);
        return (findDepth_Iterative(lca, p) + findDepth_Iterative(lca, q) - 2);
    }
};