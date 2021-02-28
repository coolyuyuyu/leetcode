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
    void recoverTree(TreeNode* root) {
        TreeNode* prev = nullptr;
        TreeNode* wrong1 = nullptr;
        TreeNode* wrong2 = nullptr;

        stack<TreeNode*> stk;
        while (root || !stk.empty()) {
            if (root) {
                stk.push(root);
                root = root->left;
            }
            else {
                root = stk.top();
                stk.pop();

                if (prev && root->val < prev->val) {
                    if (wrong1) {
                        wrong2 = root;
                    }
                    else {
                        wrong1 = prev;
                        wrong2 = root;
                    }
                }
                prev = root;

                root = root->right;
            }
        }

        swap(wrong1->val, wrong2->val);
    }
};