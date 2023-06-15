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
        vector<int> sums;
        std::function<void(TreeNode*, int)> f = [&](TreeNode* root, int depth) {
            if (!root) {
                return;
            }

            if (sums.size() <= depth) {
                sums.emplace_back(0);
            }
            sums[depth] += root->val;
            f(root->left, depth + 1);
            f(root->right, depth + 1);
        };
        f(root, 0);

        return std::distance(sums.begin(), std::max_element(sums.begin(), sums.end())) + 1;
    }

    int iterative(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }

        int maxDepth = -1, maxSum = INT_MIN;
        for (int depth = 0; !q.empty(); ++depth) {
            int sum = 0;
            for (int n = q.size(); 0 < n--;) {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }

            if (maxSum < sum) {
                maxSum = sum;
                maxDepth = depth;
            }
        }

        return maxDepth + 1;
    }

    int maxLevelSum(TreeNode* root) {
        //return recursive(root);
        return iterative(root);
    }
};
