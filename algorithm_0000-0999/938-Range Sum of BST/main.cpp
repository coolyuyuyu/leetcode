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
    int recursive(TreeNode* root, int low, int high) {
        if (!root) {
            return 0;
        }

        int ret = 0;
        if (low <= root->val && root->val <= high) {
            ret += root->val;
        }
        if (low < root->val) {
            ret += rangeSumBST(root->left, low, high);
        }
        if (root->val < high) {
            ret += rangeSumBST(root->right, low, high);
        }
        return ret;
    }

    int iterative(TreeNode* root, int low, int high) {
        queue<TreeNode*> q;
        if (root) {
            q.emplace(root);
        }

        int ret = 0;
        while (!q.empty()) {
            root = q.front();
            q.pop();

            if (low <= root->val && root->val <= high) {
                ret += root->val;
            }
            if (low < root->val && root->left) {
                q.emplace(root->left);
            }
            if (root->val < high && root->right) {
                q.emplace(root->right);
            }
        }

        return ret;
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        //return recursive(root, low, high);
        return iterative(root, low, high);
    }
};
