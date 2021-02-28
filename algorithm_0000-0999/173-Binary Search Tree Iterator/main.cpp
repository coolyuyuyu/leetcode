/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while (root) {
            m_stk.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !m_stk.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* pRet = m_stk.top();
        m_stk.pop();

        TreeNode* root = pRet->right;
        while (root) {
            m_stk.push(root);
            root = root->left;
        }

        return pRet->val;
    }
private:
    stack<TreeNode*> m_stk;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */