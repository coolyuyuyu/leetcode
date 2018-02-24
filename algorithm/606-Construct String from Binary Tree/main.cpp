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
    string tree2str(TreeNode* t) {
        string str;
        if (t) {
            str += to_string(t->val);

            string lftStr = tree2str(t->left);
            string rhtStr = tree2str(t->right);
            if (!lftStr.empty()) {
                str += ("(" + lftStr + ")");
                if (!rhtStr.empty()) {
                    str += ("(" + rhtStr + ")");
                }
            }
            else {
                if (!rhtStr.empty()) {
                    str += ("()(" + rhtStr + ")");
                }
            }
        }

        return str;
    }
};