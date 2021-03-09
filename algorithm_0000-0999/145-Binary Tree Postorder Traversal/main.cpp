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
    void postorderTraversal_Recursive(TreeNode* root, vector<int>& vals) {
        if (!root) {
            return;
        }

        postorderTraversal_Recursive(root->left, vals);
        postorderTraversal_Recursive(root->right, vals);
        vals.push_back(root->val);
    }

    void postorderTraversal_Iterative1(TreeNode* root, vector<int>& vals) {
        stack<TreeNode*> stk;
        if (root) {
            stk.push(root);
        }

        while (!stk.empty()) {
            root = stk.top();
            stk.pop();

            vals.push_back(root->val);

            if (root->left) {
                stk.push(root->left);
            }
            if (root->right) {
                stk.push(root->right);
            }
        }
        reverse(vals.begin(), vals.end());
    }

    void postorderTraversal_Iterative2(TreeNode* root, vector<int>& vals) {
        stack<pair<TreeNode*, bool>> stk;
        if (root) {
            stk.emplace(root, false);
        }

        while (!stk.empty()) {
            TreeNode* node = stk.top().first;
            bool visited = stk.top().second;
            stk.pop();

            if (visited) {
                vals.push_back(node->val);
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

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vals;

        //postorderTraversal_Recursive(root, vals);
        //postorderTraversal_Iterative1(root, vals);
        postorderTraversal_Iterative2(root, vals);


        return vals;
    }
};