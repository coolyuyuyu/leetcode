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
    bool isValidSequence_Recursive(TreeNode* root, vector<int>& arr, size_t index = 0) {
        if (!root || arr.size() <= index || root->val != arr[index]) {
            return false;
        }

        if (!root->left && !root->right && arr.size() <= (index + 1)) {
            return true;
        }
        else {
            return isValidSequence_Recursive(root->left, arr, index + 1) || isValidSequence_Recursive(root->right, arr, index + 1);
        }
    }

    bool isValidSequence_Iterative(TreeNode* root, vector<int>& arr) {
        queue<TreeNode*> q({root});
        for (size_t index = 0; !q.empty() && index < arr.size(); ++index) {
            for (size_t i = q.size(); 0 < i; --i) {
                TreeNode* node = q.front();
                q.pop();

                if (node->val == arr[index]) {
                    if (arr.size() <= (index + 1) && !node->left && !node->right) {
                        return true;
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

        return false;
    }

    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        //return isValidSequence_Recursive(root, arr);
        return isValidSequence_Iterative(root, arr);
    }
};