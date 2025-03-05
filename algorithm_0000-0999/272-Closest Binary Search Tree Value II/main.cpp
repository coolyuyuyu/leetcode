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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        queue<int> q;
        for (BSTIterator itr(root); itr.hasNext();) {
            int v = itr.next()->val;
            if (q.size() < k) {
                q.push(v);
            }
            else if (std::abs(v - target) < std::abs(q.front() - target)) {
                q.pop();
                q.push(v);
            }
            else {
                break;
            }
        }

        vector<int> ret;
        for (; !q.empty(); q.pop()) {
            ret.push_back(q.front());
        }
        return ret;
    }
};
