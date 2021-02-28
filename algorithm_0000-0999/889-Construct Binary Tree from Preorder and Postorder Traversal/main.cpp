/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        assert(pre.size() == post.size());
        return buildTree(pre, 0, post, 0, pre.size());
    }

    TreeNode* buildTree(vector<int>& pre, size_t preBgn, vector<int>& post, size_t postBgn, size_t len) {
        if (len == 0) {
            return NULL;
        }

        size_t lftLen, rhtLen;
        if (len > 1) {
            int target = pre[preBgn + 1];
            size_t postIndex = postBgn;
            for (size_t postEnd = postBgn + len - 1; postIndex < postEnd; ++postIndex) {
                if (post[postIndex] == target) {
                    break;
                }
            }
            lftLen = postIndex - postBgn + 1;
            rhtLen = len - lftLen - 1;
        }
        else {
            lftLen = rhtLen = 0;
        }

        TreeNode* root = new TreeNode(pre[preBgn]);
        root->left = buildTree(pre, preBgn + 1, post, postBgn, lftLen);
        root->right = buildTree(pre, preBgn + 1 + lftLen, post, postBgn + lftLen, rhtLen);

        return root;
    }
};