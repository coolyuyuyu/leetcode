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
    pair<int, bool> countUnivalSubtrees_Recursive(TreeNode* root) {
        if (!root) {
            return {0, true};
        }

        pair<int, bool> lftResult = countUnivalSubtrees_Recursive(root->left), rhtReult = countUnivalSubtrees_Recursive(root->right);
        int count = lftResult.first + rhtReult.first;
        bool uniVal = false;
        if ((lftResult.second && (!root->left || root->left->val == root->val)) &&
            (rhtReult.second && (!root->right || root->right->val == root->val))) {
            count += 1;
            uniVal = true;
        }

        return {count, uniVal};
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
        //return countUnivalSubtrees_Recursive(root).first;
        return countUnivalSubtrees_Iterative(root);
    }
};