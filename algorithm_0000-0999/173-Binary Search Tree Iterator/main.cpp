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
    BSTIterator(TreeNode* root) {
        while (root) {
            m_stk.push(root);
            root = root->left;
        }
    }

    int next() {
        TreeNode* ret = m_stk.top();
        m_stk.pop();

        TreeNode* root = ret->right;
        while (root) {
            m_stk.push(root);
            root = root->left;
        }

        return ret->val;
    }

    bool hasNext() {
        return !m_stk.empty();
    }

private:
    stack<TreeNode*> m_stk;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */