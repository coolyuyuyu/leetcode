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
            return node;
        }
        if (cache.find(node) != cache.end()) {
            return cache[node];
        }

        Node* copy = cache[node] = new Node(node->val);
        for (Node* neighbor : node->neighbors) {
            copy->neighbors.push_back(recursive(neighbor, cache));
        }
        return copy;
    }

    Node* iterative(Node* node, unordered_map<Node*, Node*>& cache) {
        stack<Node*> stk({node});
        while (!stk.empty()) {
            auto nodeOld = stk.top();
            stk.pop();

            if (!nodeOld) {
                continue;
            }

            if (cache.find(nodeOld) == cache.end()) {
                cache[nodeOld] = new Node(nodeOld->val);
            }
            for (Node* neighborOld : nodeOld->neighbors) {
                if (cache.find(neighborOld) == cache.end()) {
                    cache[neighborOld] = new Node(neighborOld->val);
                    stk.push(neighborOld);
                }
                cache[nodeOld]->neighbors.push_back(cache[neighborOld]);
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
