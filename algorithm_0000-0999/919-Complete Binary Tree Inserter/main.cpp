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
class CBTInserter {
public:
    CBTInserter(TreeNode* root)
        : m_root(root)
        , m_q({root}) {
    }

    int insert(int v) {
        for (TreeNode* node = m_q.front(); node->left && node->right; node = m_q.front()) {
            m_q.pop();

            m_q.push(node->left);
            m_q.push(node->right);
        }

        TreeNode** ppInsert = &(m_q.front()->left ? m_q.front()->right : m_q.front()->left);
        *ppInsert = new TreeNode(v);

        return m_q.front()->val;
    }

    TreeNode* get_root() {
        return m_root;
    }

private:
    TreeNode* m_root;
    queue<TreeNode*> m_q;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */