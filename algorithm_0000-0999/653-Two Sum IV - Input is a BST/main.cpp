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
    bool hashset_recursive(TreeNode* root, int k) {
        unordered_set<int> visited;
        std::function<bool(TreeNode*)> f = [&](TreeNode* root) {
            if (!root) {
                return false;
            }

            if (visited.find(k - root->val) != visited.end()) {
                return true;
            }
            visited.insert(root->val);

            return f(root->left) || f(root->right);
        };
        return f(root);
    }

    bool hashset_iterative(TreeNode* root, int k) {
        unordered_set<int> visited;
        for (stack<TreeNode*> stk({root}); !stk.empty();) {
            root = stk.top();
            stk.pop();

            if (!root) {
                continue;
            }
            if (visited.find(k - root->val) != visited.end()) {
                return true;
            }
            visited.insert(root->val);

            stk.push(root->left);
            stk.push(root->right);
        }

        return false;
    }

    bool convergeFromBothEnds(TreeNode* root, int k) {
        BSTIterator itrFwd(root), itrBwd(root, false);
        for (TreeNode *nodeFwd = itrFwd.next(), *nodeBwd = itrBwd.next(); nodeFwd != nodeBwd;) {
            int sum = nodeFwd->val + nodeBwd->val;
            if (sum == k) {
                return true;
            }
            else if (sum < k) {
                nodeFwd = itrFwd.next();
            }
            else {
                nodeBwd = itrBwd.next();
            }
        }

        return false;
    }

    bool findTarget(TreeNode* root, int k) {
        //return hashset_recursive(root, k);
        //return hashset_iterative(root, k);
        return convergeFromBothEnds(root, k);
    }
};
