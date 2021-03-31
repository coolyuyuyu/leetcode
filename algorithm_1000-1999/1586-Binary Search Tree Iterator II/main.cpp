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
    BSTIterator(TreeNode* root)
        : m_endIndex(0) {
        for (; root; root = root->left) {
            m_stk.emplace(root);
        }
    }

    bool hasNext() {
        return (m_endIndex < m_vals.size() || !m_stk.empty());
    }

    int next() {
        if (m_vals.size() <= m_endIndex) {
            TreeNode* root = m_stk.top();
            m_stk.pop();

            for (TreeNode* node = root->right; node; node = node->left) {
                m_stk.emplace(node);
            }

            m_vals.push_back(root->val);
            ++m_endIndex;

            return root->val;
        }
        else {
            return m_vals[m_endIndex++];
        }
    }

    bool hasPrev() {
        return (1 < m_endIndex);
    }

    int prev() {
        return m_vals[--m_endIndex - 1];
    }

private:
    stack<TreeNode*> m_stk;

    vector<int> m_vals;
    size_t m_endIndex;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * bool param_1 = obj->hasNext();
 * int param_2 = obj->next();
 * bool param_3 = obj->hasPrev();
 * int param_4 = obj->prev();
 */