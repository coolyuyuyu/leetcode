/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        stack<TreeNode*> stk;
        if (root) {
            stk.push(root);
        }

        vector<int> ans;
        vector<int>::iterator itr = voyage.begin();
        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();

            if (node->val != *itr) {
                ans.clear();
                ans.emplace_back(-1);
                break;
            }
            ++itr;

            if (node->left && node->right && node->right->val == *itr) {
                ans.emplace_back(node->val);
                swap(node->left, node->right);
            }

            if (node->right) {
                stk.push(node->right);
            }
            if (node->left) {
                stk.push(node->left);
            }
        }

        return ans;
    }
};