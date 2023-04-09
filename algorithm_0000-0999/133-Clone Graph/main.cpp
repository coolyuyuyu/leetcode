/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* recursive(Node* node, unordered_map<Node*, Node*>& cache) {
        if (!node) {
            return nullptr;
        }
        if (cache.find(node) != cache.end()) {
            return cache[node];
        }

        Node*& copy = cache[node];
        copy = new Node(node->val);
        for (Node* neighbor : node->neighbors) {
            copy->neighbors.push_back(recursive(neighbor, cache));
        }

        return copy;
    }

    Node* iterative(Node* node, unordered_map<Node*, Node*>& cache) {
        stack<Node*> stk({node});
        while (!stk.empty()) {
            Node* node = stk.top();
            stk.pop();

            if (!node) {
                continue;
            }

            Node*& copy = cache[node];
            if (!copy) {
                copy = new Node(node->val);
            }
            for (Node* neighbor : node->neighbors) {
                Node*& neighborCopy = cache[neighbor];
                if (!neighborCopy) {
                    neighborCopy = new Node(neighbor->val);
                    stk.push(neighbor);
                }

                copy->neighbors.push_back(neighborCopy);
            }
        }

        return cache[node];
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> cache;

        //return recursive(node, cache);
        return iterative(node, cache);
    }
};
