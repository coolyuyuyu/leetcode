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

    int countUnivalSubtrees(TreeNode* root, bool& unival) {
        if (!root) {
            unival = true;
            return 0;
        }

        bool lftUnival, rhtUnival;
        int count = countUnivalSubtrees(root->left, lftUnival) + countUnivalSubtrees(root->right, rhtUnival);
        if (lftUnival && rhtUnival) {
            if (root->left) {
                if (root->right) {
                    if (root->val == root->left->val && root->val == root->right->val) {
                        unival = true;
                    }
                    else {
                        unival = false;
                    }
                }
                else {
                    if (root->val == root->left->val) {
                        unival = true;
                    }
                    else {
                        unival = false;
                    }
                }
            }
            else {
                if (root->right) {
                    if (root->val == root->right->val) {
                        unival = true;
                    }
                    else {
                        unival = false;
                    }
                }
                else {
                    unival = true;
                }
            }
        }
        else {
            unival = false;
        }
        if (unival) {
            ++count;
        }

        return count;
    }

    int countUnivalSubtrees(TreeNode* root) {
        bool unival;
        return countUnivalSubtrees(root, unival);
    }
};