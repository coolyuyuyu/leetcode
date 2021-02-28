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
    vector<TreeNode*> allPossibleFBT(int N) {
        static vector<vector<TreeNode*>> cache;
        if (cache.size() <= N) {
            cache.resize(N + 1);
        }

        if (cache[N].empty() == false) {
            return cache[N];
        }

        if (N == 1) {
             cache[1] = {new TreeNode(0)};
        }
        else if (N % 2 == 1) {
            for (int i = 1; i < N; i += 2) {
                int j = N - i - 1;
                for (TreeNode* root1 : allPossibleFBT(i)) {
                    for (TreeNode* root2 : allPossibleFBT(j)) {
                        TreeNode* root = new TreeNode(0);
                        root->left = root1;
                        root->right = root2;
                        cache[N].emplace_back(root);
                    }
                }
            }
        }

        return cache[N];
    }
};