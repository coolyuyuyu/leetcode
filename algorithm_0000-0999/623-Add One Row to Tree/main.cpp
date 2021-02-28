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
    void insertOneRowRecv(TreeNode* root, int v, int d) {
        assert(0 <= d);
        if (!root) {
            return;
        }

        if (d == 0) {
            TreeNode* lftChild = new TreeNode(v);
            lftChild->left = root->left;
            root->left = lftChild;

            TreeNode* rhtChild = new TreeNode(v);
            rhtChild->right = root->right;
            root->right = rhtChild;
        }
        else {
            insertOneRowRecv(root->left, v, d - 1);
            insertOneRowRecv(root->right, v, d - 1);
        }
    }

    TreeNode* addOneRowHelper(TreeNode* root, int v, int d) {
        assert(1 <= d);

        if (d == 1) {
            TreeNode* tmp = new TreeNode(v);
            tmp->left = root;
            root = tmp;
        }
        else {
            insertOneRowRecv(root, v, d - 2);
        }

        return root;
    }

    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        return addOneRowHelper(root, v, d);
    }
};