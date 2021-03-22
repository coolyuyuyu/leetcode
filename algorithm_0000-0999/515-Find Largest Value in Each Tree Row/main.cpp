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
    void largestValues_Recursive(TreeNode* root, vector<int>& vals, int depth = 0) {
        if (!root) {
            return;
        }

        if (vals.size() <= depth) {
            vals.resize(depth + 1, numeric_limits<int>::min());
        }

        if (vals[depth] < root->val) {
            vals[depth] = root->val;
        }

        largestValues_Recursive(root->left, vals, depth + 1);
        largestValues_Recursive(root->right, vals, depth + 1);
    }

    void largestValues_Iterative(TreeNode* root, vector<int>& vals) {
        // level-order traversal
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }
        while(!q.empty()) {
            vals.push_back(numeric_limits<int>::min());
            for (size_t i = q.size(); 0 < i; --i) {
                TreeNode* node = q.front();
                q.pop();

                if (vals.back() < node->val) {
                    vals.back() = node->val;
                }

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
    }

    vector<int> largestValues(TreeNode* root) {
        vector<int> vals;

        //largestValues_Recursive(root, vals);
        largestValues_Iterative(root, vals);

        return vals;
    }
};