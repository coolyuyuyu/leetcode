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
    size_t height(TreeNode* root) {
        if (!root) {
            return 0;
        }

        size_t h = max(height(root->left), height(root->right)) + 1;
        return h;
    }

    void printTree_Recursive(TreeNode* root, const pair<size_t, size_t>& range, vector<vector<string>>::iterator itr) {
        if (!root) {
            return;
        }

        size_t index = range.first + (range.second - range.first) / 2;
        itr->at(index) = to_string(root->val);

        ++itr;
        printTree_Recursive(root->left, {range.first, index}, itr);
        printTree_Recursive(root->right, {index + 1, range.second}, itr);
    }

    void printTree_Iterative(TreeNode* root, vector<vector<string>>& ret) {
        int h = ret.size();
        int w = ret.empty() ? 0 : ret.front().size();

        queue<pair<TreeNode*, pair<size_t, size_t>>> q; // <node, range>
        if (root) {
            q.emplace(root, make_pair(0, w));
        }
        for (size_t depth = 0; !q.empty(); ++depth) {
            for (size_t i = q.size(); 0 < i; --i) {
                TreeNode* node = q.front().first;
                pair<size_t, size_t> range = q.front().second;
                q.pop();

                size_t index = range.first + (range.second - range.first) / 2;
                ret[depth][index] = to_string(node->val);

                if (node->left) {
                    q.emplace(node->left, make_pair(range.first, index));
                }
                if (node->right) {
                    q.emplace(node->right, make_pair(index + 1, range.second));
                }
            }
        }
    }

    vector<vector<string>> printTree(TreeNode* root) {
        size_t h = height(root);
        size_t w = (1 << h) - 1;
        vector<vector<string>> ret(h, vector<string>(w));

        //printTree_Recursive(root, {0, w}, ret.begin());
        printTree_Iterative(root, ret);

        return ret;
    }
};