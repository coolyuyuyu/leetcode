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
    void recursive(TreeNode* root, int d, vector<vector<int>>& ret) {
        if(!root) {
            return;
        }

        if (ret.size() <= d) {
            ret.resize(d + 1);
        }

        if (d & 1) {
            ret[d].insert(ret[d].begin(), root->val);
        }
        else {
            ret[d].push_back(root->val);
        }

        recursive(root->left, d + 1, ret);
        recursive(root->right, d + 1, ret);
    }

    void iterative(TreeNode* root, int d, vector<vector<int>>& ret) {
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }

        for (int d = 0; !q.empty(); ++d) {
            ret.emplace_back();
            for (int i = q.size(); 0 < i--;) {
                root = q.front();
                q.pop();

                if (d & 1) {
                    ret[d].insert(ret[d].begin(), root->val);
                }
                else {
                    ret[d].push_back(root->val);
                }

                if (root->left) {
                    q.push(root->left);
                }
                if (root->right) {
                    q.push(root->right);
                }
            }
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;

        //recursive(root, 0, ret);
        iterative(root, 0, ret);

        return ret;
    }
};
