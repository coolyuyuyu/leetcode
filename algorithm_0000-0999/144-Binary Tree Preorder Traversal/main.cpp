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
    void preorderTraversal_Recursive(TreeNode* root, vector<int>& vals) {
        if (!root) {
            return;
        }

        vals.push_back(root->val);
        preorderTraversal_Recursive(root->left, vals);
        preorderTraversal_Recursive(root->right, vals);
    }

    void preorderTraversal_Iterative1(TreeNode* root, vector<int>& vals) {
        stack<TreeNode*> stk;
        if (root) {
            stk.push(root);
        }

        while (!stk.empty()) {
            root = stk.top();
            stk.pop();

            vals.push_back(root->val);

            if (root->right) {
                stk.push(root->right);
            }
            if (root->left) {
                stk.push(root->left);
            }
        }
    }

    void preorderTraversal_Iterative2(TreeNode* root, vector<int>& vals) {
        stack<pair<TreeNode*, bool>> stk;
        if (root) {
            stk.emplace(root, true);
        }

        while (!stk.empty()) {
            TreeNode* node = stk.top().first;
            bool visited = stk.top().second;
            stk.pop();

            if (visited) {
                vals.push_back(node->val);

                stk.emplace(node, false);
                if (node->right) {
                    stk.emplace(node->right, true);
                }
                if (node->left) {
                    stk.emplace(node->left, true);
                }
            }
        }
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vals;

        //preorderTraversal_Recursive(root, vals);
        //preorderTraversal_Iterative1(root, vals);
        preorderTraversal_Iterative2(root, vals);

        return vals;
    }
};