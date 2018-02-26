/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        UndirectedGraphNode* copy = NULL;

        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> nodeMap;
        queue<UndirectedGraphNode*> toVisit;
        if (node) {
            copy = new UndirectedGraphNode(node->label);
            copy->neighbors.reserve(node->neighbors.size());

            nodeMap[node] = copy;
            toVisit.push(node);
        }

        while (!toVisit.empty()) {
            UndirectedGraphNode* nodeA = toVisit.front();
            toVisit.pop();

            for (UndirectedGraphNode* nodeB : nodeA->neighbors) {
                pair<unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>::iterator, bool> p = nodeMap.insert(pair<UndirectedGraphNode*, UndirectedGraphNode*>(nodeB, NULL));
                if (p.second) { // not exist
                    UndirectedGraphNode* nodeNew = new UndirectedGraphNode(nodeB->label);
                    nodeNew->neighbors.reserve(nodeB->neighbors.size());

                    p.first->second = nodeNew;
                    toVisit.push(nodeB);
                }

                nodeMap[nodeA]->neighbors.push_back(nodeMap[nodeB]);
            }
        }

        return copy;
    }
};