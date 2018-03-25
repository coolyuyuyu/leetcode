class Solution {
public:
    void eventualSafeNodesDfs(vector<vector<int>>& graph, int node, set<int>& nodes, vector<bool>& done, vector<bool>& unsafe) {
        if (done[node]) {
            return;
        }

        for (size_t i = 0; i < graph[node].size(); ++i) {
            int nbr = graph[node][i];

            if (nodes.find(nbr) != nodes.end() || unsafe[nbr]) {
                for (auto prevNode: nodes) {
                    done[prevNode] = true;
                    unsafe[prevNode] = true;
                }
                done[node] = true;
                unsafe[node] = true;
                return;
            }

            nodes.emplace(nbr);
            eventualSafeNodesDfs(graph, nbr, nodes, done, unsafe);
            nodes.erase(nbr);
        }

        done[node] = true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        size_t nodeCnt = graph.size();
        set<int> nodes;
        vector<bool> done(nodeCnt, false);
        vector<bool> unsafe(nodeCnt, false);
        for (int node = 0; node < nodeCnt; ++node) {
            nodes.emplace(node);
            eventualSafeNodesDfs(graph, node, nodes, done, unsafe);
            nodes.erase(node);
        }

        vector<int> result;
        for (int node = 0; node < nodeCnt; ++node) {
            if (unsafe[node] == false) {
                result.emplace_back(node);
            }
        }

        return result;
    }

};