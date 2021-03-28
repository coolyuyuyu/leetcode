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
    bool flipEquiv_Recursive(TreeNode* root1, TreeNode* root2) {
        if ((root1 && !root2) || (!root1 && root2)) {
            return false;
        }
        else if (!root1 && !root2) {
            return true;
        }
        else {
            if (root1->val != root2->val) {
                return false;
            }

            return (flipEquiv_Recursive(root1->left, root2->left) && flipEquiv_Recursive(root1->right, root2->right)) ||
                   (flipEquiv_Recursive(root1->left, root2->right) && flipEquiv_Recursive(root1->right, root2->left));
        }
    }

    bool flipEquiv_Iterative(TreeNode* root1, TreeNode* root2) {
        if ((root1 && !root2) || (!root1 && root2)) {
            return false;
        }

        queue<pair<TreeNode*, TreeNode*>> q;
        if (root1) {
            assert(root2);
            q.emplace(root1, root2);
        }
        while (!q.empty()) {
            TreeNode* node1 = q.front().first;
            TreeNode* node2 = q.front().second;
            q.pop();

            if (node1->val != node2->val) {
                return false;
            }

            TreeNode* lft1 = node1->left;
            TreeNode* rht1 = node1->right;
            TreeNode* lft2 = node2->left;
            TreeNode* rht2 = node2->right;
            if ((lft1 && !lft2) || (!lft1 && lft2) || (lft1 && lft2 && lft1->val != lft2->val)) {
                swap(lft2, rht2);
            }

            if ((lft1 && !lft2) || (!lft1 && lft2)) {
                return false;
            }
            else if (lft1 && lft2) {
                q.emplace(lft1, lft2);
            }
            if ((rht1 && !rht2) || (!rht1 && rht2)) {
                return false;
            }
            else if (rht1 && rht2) {
                q.emplace(rht1, rht2);
            }
        }

        return true;
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        //return flipEquiv_Recursive(root1, root2);
        return flipEquiv_Iterative(root1, root2);
    }
};