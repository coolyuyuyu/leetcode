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

// preorder Iterator
// Inorder Iterator
// Postorder Iterator
// Foreward Iterator
// Backward Iterator
// Leaves Iterator

class PreorderTraversal {
public:
    PreorderTraversal(Node* root) {
        if (root) {
            m_stk.push(root);
        }
    }
    
    Node* next() {
        assert(!m_stk.empty());
        
        Node* node = m_stk.top();
        m_stk.pop();

        if (node->right) {
            m_stk.push(node->right);
        }
        if (node->left) {
            m_stk.push(node->left);
        }
        
        return node;
    }
    
    bool hasNext() const {
        return !m_stk.empty();
    }
    
private:
    stack<Node*> m_stk;
};

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