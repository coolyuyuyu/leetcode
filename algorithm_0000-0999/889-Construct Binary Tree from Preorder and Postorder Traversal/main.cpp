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
    TreeNode* constructFromPrePost_Recursive(vector<int>& pre, size_t preIndex, vector<int>& post, size_t postIndex, size_t size, unordered_map<int, size_t>& m) {
        if (size <= 0) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(pre[preIndex]);
        if (1 < size) {
            size_t lftSize = m[pre[preIndex + 1]] - postIndex + 1;
            size_t rhtSize = size - lftSize - 1;
            root->left = constructFromPrePost_Recursive(pre, preIndex + 1, post, postIndex, lftSize, m);
            root->right = constructFromPrePost_Recursive(pre, preIndex + 1 + lftSize, post, postIndex + lftSize, rhtSize, m);
        }

        return root;
    }

    TreeNode* constructFromPrePost_Iterative(vector<int>& pre, vector<int>& post, unordered_map<int, size_t>& m) {
        TreeNode* pRoot = nullptr;

        // BFS
        queue<tuple<TreeNode**, size_t, size_t, size_t>> q; // <node, preIndex, postIndex, size>
        if (!post.empty()) {
            q.emplace(&pRoot, 0, 0, post.size());
        }
        while (!q.empty()) {
            TreeNode** ppNode = get<0>(q.front());
            size_t preIndex = get<1>(q.front());
            size_t postIndex = get<2>(q.front());
            size_t size = get<3>(q.front());
            q.pop();

            *ppNode = new TreeNode(pre[preIndex]);
            if (1 < size) {
                size_t lftSize = m[pre[preIndex + 1]] - postIndex + 1;
                if (0 < lftSize) {
                    q.emplace(&((*ppNode)->left), preIndex + 1, postIndex, lftSize);
                }

                size_t rhtSize = size - lftSize - 1;
                if (0 < rhtSize) {
                    q.emplace(&((*ppNode)->right), preIndex + 1 + lftSize, postIndex + lftSize, rhtSize);
                }
            }
        }


        return pRoot;
    }

    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        unordered_map<int, size_t> m;
        for (size_t i = 0; i < post.size(); ++i) {
            m.emplace(post[i], i);
        }

        //return constructFromPrePost_Recursive(pre, 0, post, 0, post.size(), m);
        return constructFromPrePost_Iterative(pre, post, m);
    }
};