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
    TreeNode* lowestCommonAncestor_Recursive1(TreeNode* root, TreeNode* p, TreeNode* q, int& count) {
        if (!root) {
            count = 0;
            return root;
        }

        int lftCount;
        TreeNode* pLftLCA = lowestCommonAncestor_Recursive1(root->left, p, q, lftCount);
        if (lftCount == 2) {
            count = 2;
            return pLftLCA;
        }

        int rhtCount;
        TreeNode* pRhtLCA = lowestCommonAncestor_Recursive1(root->right, p, q, rhtCount);
        if (rhtCount == 2) {
            count = 2;
            return pRhtLCA;
        }

        count = lftCount + rhtCount;
        count += (root == p ? 1 : 0);
        count += (root == q ? 1 : 0);
        return root;
    }

    TreeNode* lowestCommonAncestor_Recursive2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) {
            return root;
        }
        else {
            TreeNode* lcaP = lowestCommonAncestor_Recursive2(root->left, p, q);
            TreeNode* lcaQ = lowestCommonAncestor_Recursive2(root->right, p, q);
            if (lcaP && lcaQ) {
                return root;
            }
            else {
                return lcaP ? lcaP : lcaQ;
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

                if (node == p || node == q) {
                    m[node] = node;
                }
                else {
                    TreeNode* lcaP = (node->left ? m[node->left] : nullptr);
                    TreeNode* lcaQ = (node->right ? m[node->right] : nullptr);
                    if (lcaP && lcaQ) {
                        m[node] = node;
                    }
                    else {
                        m[node] = (lcaP ? lcaP : lcaQ);
                    }
                }
            }
            else {
                stk.top().second = true;
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
        //int count;
        //return lowestCommonAncestor_Recursive1(root, p, q, count);

        //return lowestCommonAncestor_Recursive2(root, p, q);

        return lowestCommonAncestor_Iterative(root, p, q);
    }
};