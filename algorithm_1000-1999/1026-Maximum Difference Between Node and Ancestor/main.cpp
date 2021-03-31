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
    int maxAncestorDiff_Recursive(TreeNode* root, pair<int, int>& range) {
        if (!root) {
            range = {numeric_limits<int>::max(), numeric_limits<int>::min()};
            return 0;
        }

        pair<int, int> lftRange, rhtRange;
        int lftDiff = maxAncestorDiff_Recursive(root->left, lftRange);
        int rhtDiff = maxAncestorDiff_Recursive(root->right, rhtRange);

        if (root->left || root->right) {
            range = {min(lftRange.first, rhtRange.first), max(lftRange.second, rhtRange.second)};
        }
        else {
            range = {root->val, root->val};
        }
        int diff = max(abs(range.first - root->val), abs(range.second - root->val));

        range.first = min(range.first, root->val);
        range.second = max(range.second, root->val);
        return max(diff, max(lftDiff, rhtDiff));
    }

    int maxAncestorDiff_Iterative(TreeNode* root) {
        int maxDiff = 0;

        unordered_map<TreeNode*, pair<int, int>> m; // <node, <minVal, maxVal>>

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
                pair<int, int> lftRange = (node->left ? m[node->left] : make_pair(numeric_limits<int>::max(), numeric_limits<int>::min()));
                pair<int, int> rhtRange = (node->right ? m[node->right] : make_pair(numeric_limits<int>::max(), numeric_limits<int>::min()));

                pair<int, int> range;
                if (node->left || node->right) {
                    range = {min(lftRange.first, rhtRange.first), max(lftRange.second, rhtRange.second)};
                }
                else {
                    range = {node->val, node->val};
                }

                int diff = max(abs(range.first - node->val), abs(range.second - node->val));
                if (maxDiff < diff) {
                    maxDiff = diff;
                }

                m[node] = {min(range.first, node->val), max(range.second, node->val)};
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

        return maxDiff;
    }

    int maxAncestorDiff(TreeNode* root) {
        //pair<int, int> range;
        //return maxAncestorDiff_Recursive(root, range);

        return maxAncestorDiff_Iterative(root);
    }
};