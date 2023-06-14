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
    int byBSTIterator(TreeNode* root) {
        BSTIterator itr(root);

        int ret = INT_MAX;
        for (TreeNode* pre = itr.next(), *cur = nullptr; itr.hasNext(); pre = cur) {
            cur = itr.next();
            ret = std::min(ret, cur->val - pre->val);
        }

        return ret;
    }

    int byRecursive(TreeNode* root) {
        int ret = INT_MAX;
        TreeNode* pre = nullptr;
        std::function<void(TreeNode*)> f =[&](TreeNode* root) {
            if (!root) {
                return;
            }

            f(root->left);
            if (pre) {
                ret = std::min(ret, root->val - pre->val);
            }
            pre = root;
            f(root->right);
        };
        f(root);

        return ret;
    }

    int byIterative1(TreeNode* root) {
        int ret = INT_MAX;
        TreeNode* pre = nullptr;
        for (stack<pair<TreeNode*, bool>> stk({{root, false}}); !stk.empty();) {
            auto [cur, visited] = stk.top();
            stk.pop();

            if (!cur) {
                continue;
            }

            if (visited) {
                if (pre) {
                    ret = std::min(ret, cur->val - pre->val);
                }
                pre = cur;
            }
            else {
                stk.emplace(cur->right, false);
                stk.emplace(cur, true);
                stk.emplace(cur->left, false);
            }
        }

        return ret;
    }

    int byIterative2(TreeNode* root) {
        int ret = INT_MAX;
        TreeNode* pre = nullptr;
        for (stack<TreeNode*> stk; !stk.empty() || root;) {
            if (root) {
                while (root) {
                    stk.push(root);
                    root = root->left;
                }
            }
            else {
                root = stk.top();
                stk.pop();

                if (pre) {
                    ret = std::min(ret, root->val - pre->val);
                }
                pre = root;

                root = root->right;
            }
        }

        return ret;
    }

    int getMinimumDifference(TreeNode* root) {
        //return byBSTIterator(root);
        //return byRecursive(root);
        //return byIterative1(root);
        return byIterative2(root);
    }
};
