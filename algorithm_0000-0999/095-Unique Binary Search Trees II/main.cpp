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
    TreeNode* clone(TreeNode* root, int delta) {
        std::function<TreeNode*(TreeNode*)> f = [&](TreeNode* root) -> TreeNode* {
            if (!root) {
                return nullptr;
            }

            return new TreeNode(root->val + delta, f(root->left), f(root->right));
        };

        return f(root);
    }

    vector<TreeNode*> topdn_recursive(int n) {
        vector<vector<TreeNode*>> cache(n + 1);
        cache[0].push_back(nullptr);
        std::function< vector<TreeNode*>(int)> f = [&](int n) {
            vector<TreeNode*>& ret = cache[n];
            if (!ret.empty()) {
                return ret;
            }

            for (int val = 1; val <= n; ++val) {
                int lftCnt = val - 1, rhtCnt = n - val;
                for (TreeNode* lftChild : f(lftCnt)) {
                    for (TreeNode* rhtChild : f(rhtCnt)) {
                        ret.push_back(new TreeNode(val, lftChild, clone(rhtChild, val)));
                    }
                }
            }

            return ret;
        };

        return f(n);
    }

    vector<TreeNode*> btmup_dp(int n) {
        // dp[i]: all the structurally unique BST's, which has exactly n nodes of unique values from 1 to n
        vector<vector<TreeNode*>> dp(n + 1);
        dp[0].push_back(nullptr);
        for (int i = 1; i <= n; ++i) {
            for (int val = 1; val <= i; ++val) {
                int lftCnt = val - 1, rhtCnt = i - val;
                for (TreeNode* lftChild : dp[lftCnt]) {
                    for (TreeNode* rhtChild : dp[rhtCnt]) {
                        dp[i].push_back(new TreeNode(val, lftChild, clone(rhtChild, val)));
                    }
                }
            }
        }

        return dp[n];
    }

    vector<TreeNode*> generateTrees(int n) {
        //return topdn_recursive(n);
        return btmup_dp(n);
    }
};
