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
    TreeNode* recursive(string traversal) {
        vector<pair<int, int>> pairs;
        for (int i = 0, n = traversal.size(), depth, val; i < n;) {
            for (depth = 0; i < n && traversal[i] == '-'; ++i) {
                ++depth;
            }
            for (val = 0; i < n && isdigit(traversal[i]); ++i) {
                val = val * 10 + traversal[i] - '0';
            }
            pairs.emplace_back(depth, val);
        }
        int n = pairs.size();

        std::function<pair<TreeNode*, int>(int)> dfs = [&](int cur) {
            const auto& [depth, val] = pairs[cur];

            TreeNode* root = new TreeNode(val);
            int rootCnt = 1;
            int lftCnt = 0, rhtCnt = 0;

            if (cur + 1 < n && depth + 1 == pairs[cur + 1].first) {
                auto [lft, cnt] = dfs(cur + 1);
                root->left = lft;
                lftCnt = cnt;
            }
            if (cur + lftCnt + 1 < n && depth + 1 == pairs[cur + lftCnt + 1].first) {
                auto [rht, cnt] = dfs(cur + lftCnt + 1);
                root->right = rht;
                rhtCnt = cnt;
            }

            return pair<TreeNode*, int>{root, 1 + lftCnt + rhtCnt};
        };

        return dfs(0).first;
    }

    TreeNode* iterative(string traversal) {
        stack<TreeNode*> stk;
        for (int i = 0, n = traversal.size(), depth, val; i < n;) {
            for (depth = 0; i < n && traversal[i] == '-'; ++i) {
                ++depth;
            }
            for (val = 0; i < n && isdigit(traversal[i]); ++i) {
                val = val * 10 + traversal[i] - '0';
            }

            TreeNode* node = new TreeNode(val);
            while (stk.size() > depth) {
                stk.pop();
            }
            if (!stk.empty()) {
                if (stk.top()->left) {
                    stk.top()->right = node;
                }
                else {
                    stk.top()->left = node;
                }
            }
            stk.push(node);
        }
        while (stk.size() > 1) {
            stk.pop();
        }

        return stk.top();
    }

    TreeNode* recoverFromPreorder(string traversal) {
        //return recursive(traversal);
        return iterative(traversal);
    }
};
