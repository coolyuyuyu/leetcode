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
    bool flipMatchVoyage_Recursive(TreeNode* root, vector<int>::iterator& itr, vector<int>& ret) {
        if (!root) {
            return true;
        }

        if (root->val != *itr) {
            return false;
        }
        ++itr;

        if (root->left && root->right && root->right->val == *itr) {
            swap(root->left, root->right);
            ret.push_back(root->val);
        }

        return flipMatchVoyage_Recursive(root->left, itr, ret) && flipMatchVoyage_Recursive(root->right, itr, ret);
    }

    vector<int> flipMatchVoyage_Iterative(TreeNode* root, vector<int>& voyage) {
        // preorder traversal
        stack<TreeNode*> stk;
        if (root) {
            stk.emplace(root);
        }

        vector<int> ret;
        for (vector<int>::iterator itr = voyage.begin(); !stk.empty(); ++itr) {
            TreeNode* node = stk.top();
            stk.pop();

            if (node->val != *itr) {
                ret = {-1};
                break;
            }

            if (node->left && node->right && node->right->val == *(itr + 1)) {
                swap(node->left, node->right);
                ret.push_back(node->val);
            }

            if (node->right) {
                stk.emplace(node->right);
            }
            if (node->left) {
                stk.emplace(node->left);
            }
        }

        return ret;
    }

    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int>::iterator itr = voyage.begin();
        vector<int> ret;
        if (!flipMatchVoyage_Recursive(root, itr, ret)) {
            ret = {-1};
        }
        return ret;

        //return flipMatchVoyage_Iterative(root, voyage);
    }
};