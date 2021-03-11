/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */

class PreorderIterator {
public:
    PreorderIterator(Node* root) {
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

class Solution {
public:
    bool checkEquivalence(Node* root1, Node* root2) {
        vector<int> counts(26, 0);

        for (PreorderIterator itr1(root1); itr1.hasNext();) {
            char c = itr1.next()->val;
            if (c != '+') {
                ++counts[c - 'a'];
            }
        }
        for (PreorderIterator itr2(root2); itr2.hasNext();) {
            char c = itr2.next()->val;
            if (c != '+') {
                if (counts[c - 'a'] == 0) {
                    return false;
                }
                --counts[c - 'a'];
            }
        }

        return true;
    }
};