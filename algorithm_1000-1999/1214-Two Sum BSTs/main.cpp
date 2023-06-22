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

class BSTIterator {
public:
    BSTIterator(TreeNode* root, bool forward = true)
        : m_forward(forward) {
        for (; root; root = (m_forward ? root->left : root->right)) {
            m_stk.emplace(root);
        }
    }

    bool hasNext() const {
        return !m_stk.empty();
    }

    TreeNode* next() {
        if (!hasNext()) {
            return nullptr;
        }

        TreeNode* ret = m_stk.top();
        m_stk.pop();

        for (TreeNode* root = (m_forward ? ret->right : ret->left); root; root = (m_forward ? root->left : root->right)) {
            m_stk.push(root);
        }

        return ret;
    }

private:
    bool m_forward;
    stack<TreeNode*> m_stk;
};

class Solution {
public:

    bool scanInSequential(TreeNode* root1, TreeNode* root2, int target) {
        unordered_set<int> cache;
        for (queue<TreeNode*> q({root1}); !q.empty();) {
            TreeNode* node = q.front();
            q.pop();

            if (!node) {
                continue;
            }

            cache.insert(node->val);

            q.push(node->left);
            q.push(node->right);
        }

        for (queue<TreeNode*> q({root2}); !q.empty();) {
            TreeNode* node = q.front();
            q.pop();

            if (!node) {
                continue;
            }

            if (cache.find(target - node->val) != cache.end()) {
                return true;
            }

            q.push(node->left);
            q.push(node->right);
        }

        return false;
    }

    bool convergeSearch(TreeNode* root1, TreeNode* root2, int target) {
        BSTIterator itrFwd(root1, true), itrBwd(root2, false);
        for (TreeNode *nodeFwd = itrFwd.next(), *nodeBwd = itrBwd.next(); nodeFwd && nodeBwd;) {
            int sum = nodeFwd->val + nodeBwd->val;
            if (sum == target) {
                return true;
            }
            else if (sum < target) {
                nodeFwd = itrFwd.next();
            }
            else {
                nodeBwd = itrBwd.next();
            }
        }

        return false;
    }

    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        //return scanInSequential(root1, root2, target);
        return convergeSearch(root1, root2, target);
    }
};
