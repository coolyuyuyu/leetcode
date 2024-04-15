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
    vector<int> recursive(TreeNode* root) {
        vector<int> ret;
        std::function<void(TreeNode*)> f = [&](TreeNode* root) {
            if (!root) { return; }
            if (root->left && !root->right) {
                ret.push_back(root->left->val);
            }
            else if (!root->left && root->right) {
                ret.push_back(root->right->val);
            }
            f(root->left);
            f(root->right);
        };
        f(root);

        return ret;
    }

    vector<int> iterative(TreeNode* root) {
        vector<int> ret;
        for (queue<TreeNode*> q({root}); !q.empty();) {
            auto root = q.front();
            q.pop();

            if (!root) { continue; }
            if (root->left && !root->right) {
                ret.push_back(root->left->val);
            }
            else if (!root->left && root->right) {
                ret.push_back(root->right->val);
            }
            q.push(root->left);
            q.push(root->right);
        };

        return ret;
    }

    vector<int> getLonelyNodes(TreeNode* root) {
        //return recursive(root);
        return iterative(root);
    }
};
