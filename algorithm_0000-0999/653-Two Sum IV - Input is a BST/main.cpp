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
    bool findTarget_Recursive(TreeNode* root, int k, unordered_set<int>& visited) {
        if (!root) {
            return false;
        }

        if (visited.find(k - root->val) != visited.end()) {
            return true;
        }
        visited.insert(root->val);

        return (findTarget_Recursive(root->left, k, visited) || findTarget_Recursive(root->right, k, visited));
    }

    bool findTarget_Iterative(TreeNode* root, int k) {
        unordered_set<int> visited;

        stack<TreeNode*> stk;
        if (root) {
            stk.push(root);
        }
        while (!stk.empty()) {
            root = stk.top();
            stk.pop();

            if (visited.find(k - root->val) != visited.end()) {
                return true;
            }
            visited.insert(root->val);

            if (root->right) {
                stk.push(root->right);
            }
            if (root->left) {
                stk.push(root->left);
            }
        }

        return false;
    }

    bool findTarget(TreeNode* root, int k) {
        //unordered_set<int> visited;
        //return findTarget_Recursive(root, k, visited);

        return findTarget_Iterative(root, k);
    }
};
