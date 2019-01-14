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
    string findDuplicateSubtreesV1(TreeNode* root, map<string, size_t>& counts, vector<TreeNode*>& duplicates) {
        if (!root) {
            return "";
        }

        ostringstream oss;
        oss << '(' << findDuplicateSubtreesV1(root->left, counts, duplicates) << ')';
        oss << root->val;
        oss << '(' << findDuplicateSubtreesV1(root->right, counts, duplicates) << ')';

        string id = oss.str();
        ++counts[id];
        if (counts[id] == 2) {
            duplicates.emplace_back(root);
        }

        return id;
    }

    string findDuplicateSubtreesV2(TreeNode* root, map<string, size_t>& counts, vector<TreeNode*>& duplicates) {
        if (!root) {
            return "#";
        }

        string id = to_string(root->val) + "," + findDuplicateSubtreesV2(root->left, counts, duplicates) + ","  + findDuplicateSubtreesV2(root->right, counts, duplicates);
        ++counts[id];
        if (counts[id] == 2) {
            duplicates.emplace_back(root);
        }

        return id;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<string, size_t> counts;
        vector<TreeNode*> duplicates;

        //findDuplicateSubtreesV1(root, counts, duplicates);
        findDuplicateSubtreesV2(root, counts, duplicates);

        return duplicates;
    }
};