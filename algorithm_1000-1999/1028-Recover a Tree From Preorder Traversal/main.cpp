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
    TreeNode* recursive(const string& traversal) {
        vector<pair<int, int>> pairs;
        for (int i = 0, n = traversal.size(), dep, val; i < n;) {
            for (dep = 0; i < n && traversal[i] == '-'; ++i) {
                ++dep;
            }
            for (val = 0; i < n && std::isdigit(traversal[i]); ++i) {
                val = val * 10 + traversal[i] - '0';
            }
            pairs.emplace_back(dep, val);
        }
        int n = pairs.size();

        std::function<pair<TreeNode*, int>(int)> dfs = [&](int i) {
            TreeNode* root = new TreeNode(pairs[i].second);
            int lftCnt = 0, rhtCnt  = 0;
            if (i + 1 < n && pairs[i].first + 1 == pairs[i + 1].first) {
                std::tie(root->left, lftCnt) = dfs(i + 1);
            }
            if (i + lftCnt + 1 < n && pairs[i].first + 1 == pairs[i + lftCnt + 1].first) {
                std::tie(root->right, rhtCnt) = dfs(i + lftCnt + 1);
            }

            return make_pair(root, 1 + lftCnt + rhtCnt);
        };

        return dfs(0).first;
    }

    TreeNode* iterative(const string& traversal) {
        stack<TreeNode*> stk;
        for (int i = 0, n = traversal.size(), dep, val; i < n;) {
            for (dep = 0; i < n && traversal[i] == '-'; ++i) {
                ++dep;
            }
            for (val = 0; i < n && std::isdigit(traversal[i]); ++i) {
                val = val * 10 + traversal[i] - '0';
            }

            TreeNode* node = new TreeNode(val);
            while (stk.size() > dep) {
                stk.pop();
            }
            if (!stk.empty()){
                (stk.top()->left ? stk.top()->right : stk.top()->left) = node;
            }
            stk.push(node);
        }

        TreeNode* ret = nullptr;
        for (; !stk.empty(); stk.pop()) {
            ret = stk.top();
        }
        return ret;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        //return recursive(traversal);
        return iterative(traversal);
    }
};
