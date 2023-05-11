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
    vector<vector<int>> recursive(TreeNode* root) {
        vector<vector<int>> ret;
        std::function<void(TreeNode*, int)> f = [&](TreeNode* root, int level) {
            if (!root) {
                return;
            }

            if (ret.size() <= level) {
                ret.resize(level + 1);
            }

            ret[level].push_back(root->val);

            f(root->left, level + 1);
            f(root->right, level + 1);
        };
        f(root, 0);

        return ret;
    }

    vector<vector<int>> iterative(TreeNode* root) {
        if (!root) {
            return {};
        }

        vector<vector<int>> ret;
        for (queue<TreeNode*> q({root}); !q.empty();) {
            ret.emplace_back();
            vector<int>& row = ret.back();
            for (size_t i = q.size(); 0 < i--;) {
                root = q.front();
                q.pop();

                row.push_back(root->val);
                if (root->left) {
                    q.push(root->left);
                }
                if (root->right) {
                    q.push(root->right);
                }
            }
        }

        return ret;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        //return recursive(root);
        return iterative(root);
    }
};
