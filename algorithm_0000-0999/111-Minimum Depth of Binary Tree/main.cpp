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
        if (!root) {
            return 0;
        }

        int ret = INT_MAX;
        std::function<void(TreeNode*, int)> f = [&](TreeNode* root, int depth) {
            if (ret <= depth) {
                return;
            }

            if (root->left == nullptr && root->right == nullptr) {
                ret = depth;
                return;
            }

            if (root->left) {
                f(root->left, depth + 1);
            }
            if (root->right) {
                f(root->right, depth + 1);
            }
        };
        f(root, 1);
        return ret;
    }

    int iterative(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }
        for (int depth = 1; !q.empty(); ++depth) {
            for (int i = q.size(); 0 < i--;) {
                root = q.front();
                q.pop();

                if (root->left == nullptr && root->right == nullptr) {
                    return depth;
                }

                if (root->left) {
                    q.push(root->left);
                }
                if (root->right) {
                    q.push(root->right);
                }
            }
        }

        return 0;
    }

    int minDepth(TreeNode* root) {
        //return recursive(root);
        return iterative(root);
    }
};
