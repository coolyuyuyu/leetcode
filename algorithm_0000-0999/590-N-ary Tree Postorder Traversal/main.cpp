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
        vector<int> ret;
        std::function<void(Node*)> f = [&](Node* root) {
            if (!root) { return; }
            for (Node* child : root->children) {
                f(child);
            }
            ret.push_back(root->val);
        };
        f(root);

        return ret;
    }

    vector<int> iterative(Node* root) {
        vector<int> ret;
        for (stack<pair<Node*, bool>> stk({{root, false}}); !stk.empty();) {
            auto [root, visited] = stk.top();
            stk.pop();

            if (!root) { continue; }

            if (visited) {
                ret.push_back(root->val);
            }
            else {
                stk.emplace(root, true);
                for (int i = root->children.size(); 0 < i--;) {
                    stk.emplace(root->children[i], false);
                }
            }
        }

        return ret;
    }

    vector<int> postorder(Node* root) {
        //return recursive(root);
        return iterative(root);
    }
};
