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
    vector<TreeNode*> topdnRecursion(int n) {
        // dp[i]: a list of all possible full binary trees with i nodes
        vector<TreeNode*> dp[n + 1];
        dp[1] = {new TreeNode(0)};
        std::function<vector<TreeNode*>&(int)> f = [&](int n) -> vector<TreeNode*>& {
            vector<TreeNode*>& ret = dp[n];
            if (!ret.empty()) {
                return ret;
            }

            for (int lftN = 1, rhtN = n - lftN - 1; 0 <= rhtN; lftN += 2, rhtN -= 2) {
                for (TreeNode* lft : f(lftN)) {
                    for (TreeNode* rht : f(rhtN)) {
                        ret.push_back(new TreeNode(0, lft, rht));
                    }
                }
            }

            return ret;
        };

        return f(n);
    }

    vector<TreeNode*> btmupDP(int n) {
        // dp[i]: a list of all possible full binary trees with i nodes
        vector<TreeNode*> dp[n + 1];
        dp[1] = {new TreeNode(0)};
        for (int i = 3; i <= n; i += 2) {
            for (int lftN = 1, rhtN = i - lftN - 1; 0 <= rhtN; lftN += 2, rhtN -= 2) {
                for (TreeNode* lft : dp[lftN]) {
                    for (TreeNode* rht : dp[rhtN]) {
                        dp[i].push_back(new TreeNode(0, lft, rht));
                    }
                }
            }
        }

        return dp[n];
    }

    vector<TreeNode*> allPossibleFBT(int n) {
        //return topdnRecursion(n);
        return btmupDP(n);
    }
};
