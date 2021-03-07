template<typename T>
class TreeNode {
public:
    // allow only true and false
    template<typename forward = true>
    class Iterator {
        
    };
    
    forewardIterator() {
        return Iterator<T, true>(this);
    }
    backwardIterator() {
        return Iterator<T, false>(this);
    }

    TreeNode<T>* lft;
    TreeNode<T>* rht;
    T data;
}

class BSTIterator{
public:
    BSTIterator(TreeNode* root, bool forward)
        : m_forward(forward) {
        while (root) {
            m_stk.push(root);
            root = m_forward ? root->left : root->right;
        }
    }

    bool hasNext() {
        return !m_stk.empty();
    }

    TreeNode* next() {
        TreeNode* node = m_stk.top();
        m_stk.pop();

        TreeNode* root = m_forward ? node->right : node->left;
        while (root) {
            m_stk.push(root);
            root = m_forward ? root->left : root->right;
        }

        return node;
    }

private:
    stack<TreeNode*> m_stk;
    bool m_forward;
};