/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* append(Node* l1, Node* l2) {
        if (!l1 || !l2) { return l1 ? l1 : l2; }

        std::swap(l1->left->right, l2->left->right);
        std::swap(l1->left, l2->left);

        return l1;
    };

    Node* recursive(Node* root) {

        std::function<Node*(Node*)> f = [&](Node* node) -> Node* {
            if (!node) { return nullptr; }

            Node* lft = f(node->left);
            Node* rht = f(node->right);
            node->left = node->right = node;

            return append(append(lft, node), rht);
        };
        return f(root);
    }

    Node* iterative(Node* root) {
        Node* head = nullptr;

        // inorder traversal
        stack<pair<Node*, bool>> stk({{root, false}});
        while (!stk.empty()) {
            auto [node, visited] = stk.top();
            stk.pop();

            if (!node) { continue; }

            if (visited) {
                node->left = node->right = node;
                head = append(head, node);
            }
            else {
                stk.emplace(node->right, false);
                stk.emplace(node, true);
                stk.emplace(node->left, false);
            }
        }

        return head;
    }

    Node* treeToDoublyList(Node* root) {
        //return recursive(root);
        return iterative(root);
    }
};
