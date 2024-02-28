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
        int maxLvl = -1;
        int ret;
        std::function<void(TreeNode*, int)> f = [&](TreeNode* root, int lvl) {
            if (!root) { return; }

            if (lvl > maxLvl) {
                maxLvl = lvl;
                ret = root->val;
            }
            f(root->left, lvl + 1);
            f(root->right, lvl + 1);
        };
        f(root, 0);

        return ret;
    }

    int iterative(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) {
            q.emplace(root);
        }

        while (!q.empty()) {
            root = q.front();
            q.pop();

            if (root->right) {
                q.emplace(root->right);
            }
            if (root->left) {
                q.emplace(root->left);
            }  
        }

        return root->val;
    }

    int findBottomLeftValue(TreeNode* root) {
        //return recursive(root);
        return iterative(root);
    }
};
