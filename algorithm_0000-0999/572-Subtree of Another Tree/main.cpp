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
    bool isSame_dfsRecv(TreeNode* p, TreeNode* q) {
        if (!p || !q) {
            return p == q;
        }
        return p->val == q->val && isSame_dfsRecv(p->left, q->left) && isSame_dfsRecv(p->right, q->right);
    }

    // Time: O(MN)
    bool isSubtree_dfsRecv(TreeNode* p, TreeNode* q) {
        if (!p || !q) {
            return p == q;
        }
        return isSame_dfsRecv(p, q) || isSubtree_dfsRecv(p->left, q) || isSubtree_dfsRecv(p->right, q);
    }

    bool isSame_dfsIter(TreeNode* p, TreeNode* q) {
        assert(p && q);

        stack<pair<TreeNode*, TreeNode*>> stk({{p, q}});
        while (!stk.empty()) {
            auto [p, q] = stk.top();
            stk.pop();

            if (!p && !q) {
                continue;
            }
            if (p && !q || !p && q || p->val != q->val) {
                return false;
            }

            stk.emplace(p->right, q->right);
            stk.emplace(p->left, q->left);
        }

        return true;
    }

    // Time: O(MN)
    bool isSubtree_dfsIter(TreeNode* p, TreeNode* q) {
        assert(p && q);

        stack<TreeNode*> stk({p});
        while (!stk.empty()) {
            p = stk.top();
            stk.pop();

            if (!p) {
                continue;
            }
            if (isSame_dfsIter(p, q)) {
                return true;
            }

            stk.push(p->right);
            stk.push(p->left);
        }

        return false;
    }

    void serialize(TreeNode* p, vector<int>& vals) {
        if (!p) {
            vals.push_back(INT_MAX);
        }
        else {
            vals.push_back(p->val);
            serialize(p->left, vals);
            serialize(p->right, vals);
        }
    }

    // Time: O(M+N)
    bool isSubtree_kmp(TreeNode* p, TreeNode* q) {
        vector<int> s; serialize(p, s);
        vector<int> t; serialize(q, t);

        if (s.size() < t.size()) {
            return false;
        }

        // suffix[i]: the longest length k such that t[0:k-1] == t[i-k+1:i]
        vector<size_t> suffix(t.size());
        suffix[0] = 0;
        for (size_t i = 1; i < t.size(); ++i) {
            size_t j = suffix[i - 1];
            while (0 < j && t[j] != t[i]) {
                j = suffix[j - 1];
            }
            suffix[i] = j + (t[j] == t[i] ? 1 : 0);
        }

        // dp[i]: the longest length k such that t[0:k-1] == s[i-k+1:i]
        size_t dp = (t[0] == s[0] ? 1 : 0);
        if (dp == 1 && t.size() == 1) {
            return true;
        }
        for (size_t i = 1; i < s.size(); ++i) {
            size_t j = dp;
            while (0 < j && t[j] != s[i]) {
                j = suffix[j - 1];
            }
            dp = j + (t[j] == s[i] ? 1 : 0);
            if (dp == t.size()) {
                return true;
            }
        }

        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        //return isSubtree_dfsRecv(root, subRoot);
        //return isSubtree_dfsIter(root, subRoot);
        return isSubtree_kmp(root, subRoot);
    }
};
