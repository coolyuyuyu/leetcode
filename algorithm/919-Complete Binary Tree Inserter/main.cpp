/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        assert(root);

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            m_nodes.push_back(node);

            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
    }

    int insert(int v) {
        TreeNode* node = new TreeNode(v);
        size_t index = m_nodes.size();
        m_nodes.push_back(node);

        TreeNode* parent = m_nodes[index / 2 - (index % 2 == 0 ? 1 : 0)];
        if (index % 2 == 0) {
            parent->right = node;
        }
        else {
            parent->left = node;
        }
        return parent->val;
    }

    TreeNode* get_root() {
        return m_nodes.front();
    }

private:
    vector<TreeNode*> m_nodes;
    TreeNode* m_root;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */