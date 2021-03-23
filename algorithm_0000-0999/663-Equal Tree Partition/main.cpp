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
    int sum_Recursive(TreeNode* root, vector<int>& sums) {
        if (!root) {
            return 0;
        }

        int sum = sum_Recursive(root->left, sums) + root->val + sum_Recursive(root->right, sums);
        sums.push_back(sum);
        return sum;
    }

    int sum_Iterative(TreeNode* root, vector<int>& sums) {
        unordered_map<TreeNode*, int> m; // <tree, sum>

        // postorder traversal
        stack<pair<TreeNode*, bool>> stk; // <node, visited>
        if (root) {
            stk.emplace(root, false);
        }
        while (!stk.empty()) {
            TreeNode* node = stk.top().first;
            bool visited = stk.top().second;
            stk.pop();

            if (visited) {
                int lftSum = (node->left ? m[node->left] : 0);
                int rhtSum = (node->right ? m[node->right] : 0);
                int sum = lftSum + node->val + rhtSum;

                sums.push_back(sum);
                m[node] = sum;
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

    bool checkEqualTree(TreeNode* root) {
        vector<int> sums;

        int sum = sum_Recursive(root, sums);
        //int sum = sum_Iterative(root, sums);

        sums.pop_back();

        if (sum % 2 == 0) { // even
            return (find(sums.begin(), sums.end(), sum / 2) != sums.end());
        }
        else { //odd
            return false;
        }
    }
};