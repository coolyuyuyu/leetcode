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
    void inorderTraversal_Recursive(TreeNode* root, vector<int>& vals) {
        if (!root) {
            return;
        }

        inorderTraversal_Recursive(root->left, vals);
        vals.push_back(root->val);
        inorderTraversal_Recursive(root->right, vals);
    }

    void inorderTraversal_Iterative1(TreeNode* root, vector<int>& vals) {
        stack<TreeNode*> stk;
        while (root || !stk.empty()) {
            if (root) {
                while (root) {
                    stk.push(root);
                    root = root->left;
                }
            }
            else {
                root = stk.top();
                stk.pop();

                vals.push_back(root->val);
                root = root->right;
            }
        }
    }

    void inorderTraversal_Iterative2(TreeNode* root, vector<int>& vals) {
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
                if (node->right) {
                    stk.emplace(node->right, false);
                }
                stk.emplace(node, true);
                if (node->left) {
                    stk.emplace(node->left, false);
                }
            }
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vals;

        //inorderTraversal_Recursive(root, vals);
        //inorderTraversal_Iterative1(root, vals);
        inorderTraversal_Iterative2(root, vals);

        return vals;
    }
};