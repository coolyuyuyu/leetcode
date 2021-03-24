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
    void maxLevelSum_Recursive(TreeNode* root, vector<int>& sums, int depth = 0) {
        if (!root) {
            return;
        }

        if (sums.size() <= depth) {
            sums.push_back(0);
        }
        sums[depth] += root->val;

        maxLevelSum_Recursive(root->left, sums, depth + 1);
        maxLevelSum_Recursive(root->right, sums, depth + 1);
    }

    void maxLevelSum_Iterative(TreeNode* root, vector<int>& sums) {
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }

        for (int depth = 0; !q.empty(); ++depth) {
            sums.push_back(0);
            for (int i = q.size(); 0 < i; --i) {
                TreeNode* node = q.front();
                q.pop();

                sums[depth] += node->val;

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
    }

    int maxLevelSum(TreeNode* root) {
        vector<int> sums;

        //maxLevelSum_Recursive(root, sums);
        maxLevelSum_Iterative(root, sums);

        return (max_element(sums.begin(), sums.end()) - sums.begin() + 1);
    }
};