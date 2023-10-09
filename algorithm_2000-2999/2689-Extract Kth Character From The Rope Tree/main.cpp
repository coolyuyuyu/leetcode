/**
 * Definition for a rope tree node.
 * struct RopeTreeNode {
 *     int len;
 *     string val;
 *     RopeTreeNode *left;
 *     RopeTreeNode *right;
 *     RopeTreeNode() : len(0), val(""), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(string s) : len(0), val(std::move(s)), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(int x) : len(x), val(""), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(int x, RopeTreeNode *left, RopeTreeNode *right) : len(x), val(""), left(left), right(right) {}
 * };
 */
class Solution {
public:
    char getKthCharacter(RopeTreeNode* root, int k) {
        if (root->len == 0) {
            return root->val[k - 1];
        }

        if (root->left == nullptr) {
            return getKthCharacter(root->right, k);
        }
        else if (k > (root->left->val.size() + root->left->len)) {
            return getKthCharacter(root->right, k - root->left->val.size() - root->left->len);
        }
        else {
            return getKthCharacter(root->left, k);
        }
    }
};
