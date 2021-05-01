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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }

        for (bool isEven = true; !q.empty(); isEven = !isEven) {
            int* pPreVal = nullptr;
            for (size_t i = q.size(); 0 < i; --i) {
                TreeNode* node = q.front();
                q.pop();

                if (isEven) {
                    if (node->val % 2 == 0 || (pPreVal && (node->val <= *pPreVal))) {
                        return false;
                    }
                }
                else {
                    if (node->val % 2 == 1 || (pPreVal && (*pPreVal <= node->val))) {
                        return false;
                    }
                }
                pPreVal = &(node->val);

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }

        return true;
    }
};
