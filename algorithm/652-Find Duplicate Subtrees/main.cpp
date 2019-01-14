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
    string findDuplicateSubtrees(TreeNode* root, map<string, size_t>& inorderMap, vector<TreeNode*>& duplicates) {
        if (!root) {
            return "";
        }

        ostringstream oss;
        oss << '(' << findDuplicateSubtrees(root->left, inorderMap, duplicates) << ')';
        oss << root->val;
        oss << '(' << findDuplicateSubtrees(root->right, inorderMap, duplicates) << ')';

        string inorder = oss.str();
        ++inorderMap[inorder];
        if (inorderMap[inorder] == 2) {
            duplicates.emplace_back(root);
        }

        return inorder;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<string, size_t> inorderMap;
        vector<TreeNode*> duplicates;
        findDuplicateSubtrees(root, inorderMap, duplicates);
        return duplicates;
    }
};