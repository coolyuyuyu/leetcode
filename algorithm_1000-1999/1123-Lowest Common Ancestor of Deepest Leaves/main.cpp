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
    TreeNode* recursive1(TreeNode* root) {
        int maxDep = -1;
        int maxDepCnt = 0;
        std::function<void(TreeNode*, int)> dfs1 = [&](TreeNode* root, int dep) {
            if (!root) { return; }
            if (dep > maxDep) {
                maxDep = dep;
                maxDepCnt = 0;
            }
            if (dep == maxDep) {
                ++maxDepCnt;
            }
            dfs1(root->left, dep + 1);
            dfs1(root->right, dep + 1);
        };
        dfs1(root, 0);

        TreeNode* ret = nullptr;
        std::function<int(TreeNode*, int)> dfs2 = [&](TreeNode* root, int dep) {
            if (!root) { return 0; }

            int cnt = (dep == maxDep ? 1 : 0) + dfs2(root->left, dep + 1) + dfs2(root->right, dep + 1);
            if (cnt == maxDepCnt && !ret) {
                ret = root;
            }

            return cnt;
        };
        dfs2(root, 0);

        return ret;
    }

    TreeNode* recursive2(TreeNode* root) {
        std::function<pair<TreeNode*, int>(TreeNode*, int)> dfs = [&](TreeNode* root, int dep) {
            if (!root) { return std::make_pair((TreeNode*)nullptr, dep); }
            auto [lftRoot, lftH] = dfs(root->left, dep + 1);
            auto [rhtRoot, rhtH] = dfs(root->right, dep + 1);
            if (lftH < rhtH) {
                return std::make_pair(rhtRoot, rhtH);
            }
            else if (lftH == rhtH) {
                return std::make_pair(root, rhtH);
            }
            else {
                return std::make_pair(lftRoot, lftH);
            }
        };

        return dfs(root, 0).first;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        //return recursive1(root);
        return recursive2(root);
    }
};
