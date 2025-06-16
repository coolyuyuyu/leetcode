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
    bool checkEqualTree(TreeNode* root) {
        std::function<int(TreeNode*)> sumTree = [&](TreeNode* root) {
            if (!root) { return 0; }
            return sumTree(root->left) + root->val + sumTree(root->right);
        };
        int sum = sumTree(root);
        if (sum & 1) { return false; }

        bool found = false;
        int target = sum / 2;

        std::function<int(TreeNode*)> checkTree = [&](TreeNode* node) {
            if (found) { return 0; }
            if (!node) { return 0; }

            int ret = checkTree(node->left) + node->val + checkTree(node->right);
            if (ret == target && node != root) {
                found = true;
            }

            return ret;
        };
        checkTree(root);
        
        return found;
    }
};
