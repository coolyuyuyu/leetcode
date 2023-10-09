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
    char recursive(RopeTreeNode* root, int k) {
        if (root->len == 0) {
            return root->val[k - 1];
        }
        int lftLen = (root->left ? (root->left->val.size() + root->left->len) : 0);
        if (k > lftLen) {
            return getKthCharacter(root->right, k - lftLen);
        }
        else {
            return getKthCharacter(root->left, k);
        }
    }

    char iterative(RopeTreeNode* root, int k) {
        while (root->len != 0) {
            int lftLen = (root->left ? (root->left->val.size() + root->left->len) : 0);
            if (k > lftLen) {
                root = root->right;
                k -= lftLen;
            }
            else {
                root = root->left;
            }
        }

        return root->val[k - 1];
    }
    
    char getKthCharacter(RopeTreeNode* root, int k) {
        //return recursive(root, k);
        return iterative(root, k);
    }
};
