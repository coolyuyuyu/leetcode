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
    int findTreeSums_Recursive(TreeNode* root, unordered_map<int, int>& counts, int& maxCount) {
        if (!root) {
            return 0;
        }

        int sum = findTreeSums_Recursive(root->left, counts, maxCount) + root->val + findTreeSums_Recursive(root->right, counts, maxCount);
        ++counts[sum];
        if (maxCount < counts[sum]) {
            maxCount = counts[sum];
        }
        return sum;
    }

    void findTreeSums_Iterative(TreeNode* root, unordered_map<int, int>& counts, int& maxCount) {
        map<TreeNode*, int> m; // <node, sum>

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
                int lftSum = (node->left ? m[node->left] : 0);
                int rhtSum = (node->right ? m[node->right] : 0);
                int sum = lftSum + node->val + rhtSum;
                m[node] = sum;

                ++counts[sum];
                if (maxCount < counts[sum]) {
                    maxCount = counts[sum];
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
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> counts;
        int maxCount = 0;

        //findTreeSums_Recursive(root, counts, maxCount);
        findTreeSums_Iterative(root, counts, maxCount);

        vector<int> ret;
        for (const auto& p : counts) {
            if (p.second == maxCount) {
                ret.push_back(p.first);
            }
        }
        return ret;
    }
};