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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q({root});
        for (int lvl = 0; !q.empty(); ++lvl) {
            int eoBit = lvl & 1;
            std::function<bool(int, int)> cmp;
            int pre = lvl & 1 ? INT_MAX : INT_MIN;
            if (lvl & 1) {
                cmp = std::less<int>();
            }
            else {
                cmp = std::greater<int>();
            }
            for (int i = q.size(); 0 < i--;) {
                TreeNode* node = q.front();
                q.pop();
                if (!node) { continue; }

                if ((node->val & 1) ^ eoBit == 0 || !cmp(node->val, pre)) {
                    return false;
                }
                pre = node->val;

                q.push(node->left);
                q.push(node->right);
            }
        }

        return true;
    }
};
