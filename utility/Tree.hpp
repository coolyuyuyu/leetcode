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

class LeafIterator {
public:
    LeafIterator(Node* root) {
        if (root) {
            m_stk.push(root);
        }
    }

    Node* next() {
        assert(!m_stk.empty());
        assert(!m_stk.top()->left && !m_stk.top()->right);

        Node* node = m_stk.top();
        m_stk.pop();

        return node;
    }

    bool hasNext() const {
        while (!m_stk.empty()) {
            Node* node = m_stk.top();
            if (!node->left && !node->right) {
                return true;
            }

            m_stk.pop();

            if (node->right) {
                m_stk.push(node->right);
            }
            if (node->left) {
                m_stk.push(node->left);
            }
        }

        return false;
    }

private:
    mutable stack<Node*> m_stk;
};

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
