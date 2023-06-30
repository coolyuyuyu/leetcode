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

    int countUnivalSubtrees_Iterative(TreeNode* root) {
        map<TreeNode*, pair<int, bool>> m = {{nullptr, {0, true}}}; // node -> <count, uniVal>

        stack<pair<TreeNode*, bool>> stk;
        if (root) {
            stk.emplace(root, false);
        }
        while (!stk.empty()) {
            TreeNode* node = stk.top().first;
            bool visited = stk.top().second;
            stk.pop();

            if (visited) {
                pair<int, bool> lftResult = m[node->left], rhtReult = m[node->right];
                int count = lftResult.first + rhtReult.first;
                bool uniVal = false;
                if ((lftResult.second && (!node->left || node->left->val == node->val)) &&
                    (rhtReult.second && (!node->right || node->right->val == node->val))) {
                    count += 1;
                    uniVal = true;
                }
                m[node] = {count, uniVal};
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

        return m[root].first;
    }


    int countUnivalSubtrees(TreeNode* root) {
        //return recursive(root);
        return countUnivalSubtrees_Iterative(root);
    }
};