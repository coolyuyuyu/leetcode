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
    vector<TreeNode*> topdn_recursion(int n) {
        if (n == 1) {
            return {new TreeNode(0)};
        }

        vector<TreeNode*> ret;
        for (int i = 1; i < n; i += 2) {
            for (TreeNode* lft : topdn_recursion(i)) {
                for (TreeNode* rht : topdn_recursion(n - i - 1)) {
                    ret.push_back(new TreeNode(0, lft, rht));
                }
            }
        }

        return ret;
    }

    vector<TreeNode*> topdn_recursion_memo(int n) {
        vector<vector<TreeNode*>> cache(n + 1);
        cache[1] = {new TreeNode(0)};
        std::function<vector<TreeNode*>(int)> f = [&](int n) {
            vector<TreeNode*>& ret = cache[n];
            if (!ret.empty()) {
                return ret;
            }

            for (int i = 1; i < n; i += 2) {
                for (TreeNode* lft : f(i)) {
                    for (TreeNode* rht : f(n - i - 1)) {
                        ret.push_back(new TreeNode(0, lft, rht));
                    }
                }
            }

            return ret;
        };

        return f(n);
    }

    vector<TreeNode*> btmup_dp(int n) {
        // dp[i]: all possible full binary trees with i nodes
        vector<vector<TreeNode*>> dp(n + 1);
        dp[1] = {new TreeNode(0)};
        for (int i = 3; i <= n; i += 2) {
            for (int j = 1; j < i; j += 2) {
                for (TreeNode* lft : dp[j]) {
                    for (TreeNode* rht : dp[i - j - 1]) {
                        dp[i].push_back(new TreeNode(0, lft, rht));
                    }
                }
            }
        }

        return dp[n];
    }

    vector<TreeNode*> allPossibleFBT(int n) {
        //return topdn_recursion(n);
        //return topdn_recursion_memo(n);
        return btmup_dp(n);
    }
};
