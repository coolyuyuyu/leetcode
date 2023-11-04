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
    int recursive(TreeNode* root) {
        if (!root) { return 0; }

        int ret = INT_MAX;
        std::function<void(TreeNode*, int)> f = [&](TreeNode* root, int d) {
            if (ret <= d) { return; }
            if (!root) { return; }
            if (root->left == nullptr && root->right == nullptr) {
                ret = std::min(ret, d);
            }
            f(root->left, d + 1);
            f(root->right, d + 1);
        };
        f(root, 1);

        return ret;
    }

    int iterative(TreeNode* root) {
        queue<TreeNode*> q({root});
        for (int d = 1; !q.empty(); ++d) {
            for (int i = q.size(); 0 < i--;) {
                root = q.front();
                q.pop();

                if (!root) { continue; }

                if (root->left == nullptr && root->right == nullptr) {
                    return d;
                }
                q.push(root->left);
                q.push(root->right);
            }
        }

        return 0;
    }

    int minDepth(TreeNode* root) {
        //return recursive(root);
        return iterative(root);
    }
};
