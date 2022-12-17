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
    Node* recursive(Node* pNode, unordered_map<Node*, Node*>& cache) {
        if (!pNode) {
            return nullptr;
        }
        if (cache.find(pNode) != cache.end()) {
            return cache[pNode];
        }

        Node* pCopy = new Node(pNode->val);
        cache[pNode] = pCopy;
        for (auto& neighbor : pNode->neighbors) {
            pCopy->neighbors.push_back(recursive(neighbor, cache));
        }
        return pCopy;
    }

    Node* recursive(Node* pNode) {
        unordered_map<Node*, Node*> cache;
        return recursive(pNode, cache);
    }

    Node* iterative(Node* pNode) {
        unordered_map<Node*, Node*> cache;

        Node* pRet = nullptr;
        queue<Node*> q;
        if (pNode) {
            pRet = new Node(pNode->val);
            cache[pNode] = pRet;
            q.push(pNode);
        }

        while (!q.empty()) {
            pNode = q.front();
            q.pop();

            Node* pNodeCopy = cache[pNode];
            for (auto neighbor : pNode->neighbors) {
                Node* pNeighborCopy;
                auto itr = cache.find(neighbor);
                if (itr == cache.end()) { // not found
                    pNeighborCopy = new Node(neighbor->val);
                    cache[neighbor] = pNeighborCopy;
                    q.push(neighbor);
                }
                else {
                    pNeighborCopy = cache[neighbor];
                }

                pNodeCopy->neighbors.push_back(pNeighborCopy);
            }
        }

        return pRet;
    }

    Node* cloneGraph(Node* node) {
        //return recursive(node);
        return iterative(node);
    }
};
