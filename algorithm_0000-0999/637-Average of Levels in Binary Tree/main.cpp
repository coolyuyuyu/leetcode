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
    void averageOfLevels_Recursive(TreeNode* root, int depth, vector<double>& sums, vector<size_t>& cnts) {
        if (!root) {
            return;
        }

        assert(sums.size() == cnts.size());
        if (sums.size() <= depth) {
            sums.resize(depth + 1, 0.0);
            cnts.resize(depth + 1, 0);
        }
        sums[depth] += root->val;
        cnts[depth] += 1;

        averageOfLevels_Recursive(root->left, depth + 1, sums, cnts);
        averageOfLevels_Recursive(root->right, depth + 1, sums, cnts);
    }

    vector<double> averageOfLevels_Iterative(TreeNode* root) {
        vector<double> avgs;

        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }
        while (!q.empty()) {
            double sum = 0;
            size_t n = q.size();
            for (size_t i = 0; i < n; ++i) {
                root = q.front();
                q.pop();

                sum += root->val;

                if (root->left) {
                    q.push(root->left);
                }
                if (root->right) {
                    q.push(root->right);
                }
            }
            avgs.push_back(sum / n);
        }

        return avgs;
    }

    vector<double> averageOfLevels(TreeNode* root) {
        //vector<double> sums;
        //vector<size_t> cnts;
        //averageOfLevels_Recursive(root, 0, sums, cnts);
        //for (size_t i = 0; i < sums.size(); ++i) {
        //    sums[i] /= cnts[i];
        //}
        //return sums;

        return averageOfLevels_Iterative(root);
    }
};