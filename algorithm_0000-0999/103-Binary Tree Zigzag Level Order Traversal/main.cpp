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
    void zigzagLevelOrder_Recursive(TreeNode* root, int depth, vector<vector<int>>& ret) {
        if (!root) {
            return;
        }

        if (ret.size() <= depth) {
            ret.resize(depth + 1);
        }

        if (depth % 2 == 0) {
            ret[depth].push_back(root->val);
        }
        else {
            ret[depth].insert(ret[depth].begin(), root->val);
        }
        zigzagLevelOrder_Recursive(root->left, depth + 1, ret);
        zigzagLevelOrder_Recursive(root->right, depth + 1, ret);
    }

    vector<vector<int>> zigzagLevelOrder_Iterative(TreeNode* root) {
        vector<vector<int>> ret;

        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }
        for (bool flip = false; !q.empty(); flip = !flip) {
            size_t len = q.size();
            ret.emplace_back(len);
            for (size_t i = 0; i < len; ++i) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }

                ret.back()[flip ? (len - i - 1) : i] = node->val;
            }
        }

        return ret;
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        zigzagLevelOrder_Recursive(root, 0, ret);
        return ret;

        //return zigzagLevelOrder_Iterative(root);
    }
};