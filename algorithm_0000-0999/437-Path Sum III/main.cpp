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
    void pathSum_Recursive(TreeNode* root, int sum, int target, map<int, int>& m, int& numPaths) {
        if (!root) {
            return;
        }

        sum += root->val;
        if (sum == target) {
            ++numPaths;
        }

        auto itr = m.find(sum - target);
        if (itr != m.end()) {
            numPaths += itr->second;
        }

        ++m[sum];
        pathSum_Recursive(root->left, sum, target, m, numPaths);
        pathSum_Recursive(root->right, sum, target, m, numPaths);
        --m[sum];
    }

    int pathSum_Iterative(TreeNode* root, int target) {
        int sum = 0;
        int numPaths = 0;
        map<int, int> m;

        stack<pair<TreeNode*, bool>> stk;
        if (root) {
            stk.emplace(root, false);
        }
        while (!stk.empty()) {
            TreeNode* node = stk.top().first;
            bool visited = stk.top().second;
            stk.pop();

            if (visited) {
                --m[sum];
                sum -= node->val;
            }
            else {
                sum += node->val;
                if (sum == target) {
                    ++numPaths;
                }

                auto itr = m.find(sum - target);
                if (itr != m.end()) {
                    numPaths += itr->second;
                }

                ++m[sum];

                stk.emplace(node, true);
                if (node->right) {
                    stk.emplace(node->right, false);
                }
                if (node->left) {
                    stk.emplace(node->left, false);
                }
            }
        }

        return numPaths;
    }

    int pathSum(TreeNode* root, int sum) {
        //map<int, int> m; // <sum, number of path (from root to some in middle) equal to sum>
        //int numPaths = 0;
        //pathSum_Recursive(root, 0, sum, m, numPaths);
        //return numPaths;

        return pathSum_Iterative(root, sum);
    }
};