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
    int recursive(TreeNode* root) {
        int ret = 0;
        std::function<bool(TreeNode*)> isUni = [&](TreeNode* root) {
            if (!root) {
                return true;
            }

            bool lftUni = isUni(root->left) , rhtUni = isUni(root->right);
            if (lftUni && (!(root->left) || root->val == root->left->val) &&
                rhtUni && (!(root->right) || root->val == root->right->val) ) {
                ++ret;
                return true;
            }
            return false;
        };
        isUni(root);

        return ret;
    }

    int iterative(TreeNode* root) {
        int ret = 0;

        map<TreeNode*, bool> m;
        stack<pair<TreeNode*, bool>> stk({{root, false}});
        while (!stk.empty()) {
            auto [node, visited] = stk.top();
            stk.pop();

            if (!node) {
                continue;
            }

            if (visited) {
                bool isUni = 
                    (!(node->left) || (m[node->left] && node->val == node->left->val)) &&
                    (!(node->right) || (m[node->right] && node->val == node->right->val));
                if (isUni) {
                    ++ret;
                    m[node] = true;
                }
            }
            else {
                stk.emplace(node, true);
                stk.emplace(node->right, false);
                stk.emplace(node->left, false);
            }
        }

        return ret;
    }

    int countUnivalSubtrees(TreeNode* root) {
        return recursive(root);
        //return iterative(root);
    }
};
