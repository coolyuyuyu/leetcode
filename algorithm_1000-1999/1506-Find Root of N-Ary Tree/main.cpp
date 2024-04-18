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
    Node* byDegree(vector<Node*> tree) {
        unordered_set<Node*> nodes(tree.begin(), tree.end());
        for (Node* node : tree) {
            for (Node* child : node->children) {
                nodes.erase(child);
            }
        }

        return *nodes.begin();
    }

    Node* byXOR(vector<Node*> tree) {
        int sum = 0;
        for (Node* node : tree) {
            sum ^= node->val;
            for (Node* child : node->children) {
                sum ^= child->val;
            }
        }

        for (Node* node : tree) {
            if (node->val == sum) {
                return node;
            }
        }

        assert(false);
        return nullptr;
    }

    Node* findRoot(vector<Node*> tree) {
        //return byDegree(tree);
        return byXOR(tree);
    }
};
