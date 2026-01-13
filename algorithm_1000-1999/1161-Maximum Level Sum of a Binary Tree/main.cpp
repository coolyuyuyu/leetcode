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
        int maxSum = INT_MIN;
        int ret = 0;

        queue<TreeNode*> q({root});
        for (int lvl = 1; !q.empty(); ++lvl) {
            int sum = 0;
            for (int i = q.size(); 0 < i--;) {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if (node->left) { q.push(node->left); }
                if (node->right) { q.push(node->right); }
            }
            if (sum > maxSum) {
                maxSum = sum;
                ret = lvl;
            }
        }

        return ret;
    }

    int maxLevelSum(TreeNode* root) {
        //return recursive(root);
        return iterative(root);
    }
};
