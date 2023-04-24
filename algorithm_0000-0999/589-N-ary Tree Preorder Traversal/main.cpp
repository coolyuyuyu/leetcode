/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> recursive(Node* root) {
        vector<int> nums;
        std::function<void(Node*)> f = [&nums, &f](Node* root) {
            if (!root) {
                return;
            }

            nums.push_back(root->val);
            for (Node* node : root->children) {
                f(node);
            }
        };
        f(root);

        return nums;
    }

    vector<int> iterative(Node* root) {
        stack<Node*> stk;
        if (root) {
            stk.push(root);
        }

        vector<int> nums;
        while (!stk.empty()) {
            root = stk.top();
            stk.pop();

            nums.push_back(root->val);
            for (size_t i = root->children.size(); 0 < i--;) {
                stk.push(root->children[i]);
            }
        }

        return nums;
    }

    vector<int> preorder(Node* root) {
        //return recursive(root);
        return iterative(root);
    }
};
