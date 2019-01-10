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
    TreeNode* str2tree(const string& str, size_t bgn, size_t end) {
        if (end <= bgn) {
            return nullptr;
        }

        bool negative = false;
        if (str[bgn] == '-') {
            ++bgn;
            negative = true;
        };

        int val = 0;
        for (; bgn < end && isdigit(str[bgn]); ++bgn) {
            val *= 10;
            val += str[bgn] - '0';
        }
        if (negative) {
            val = -val;
        }

        TreeNode* root = new TreeNode(val);

        size_t bgnLft = ++bgn;
        for (int parentheses = 1; bgn < end && parentheses != 0; ++bgn) {
            switch (str[bgn]) {
                case '(':
                    ++parentheses;
                    break;
                case ')':
                    --parentheses;
                    break;
            }
        }

        root->left = str2tree(str, bgnLft, bgn - 1);
        root->right = str2tree(str, bgn + 1, end - 1);

        return root;
    }

    TreeNode* str2tree(const string& str) {
        return str2tree(str, 0, str.size());
    }
};Z