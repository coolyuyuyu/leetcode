class Solution {
public:
    int depth_Recursive(vector<set<int>>& graph, int cur, int pre, int& diameter) {
        int depth1st = 0, depth2nd = 0;
        for (int neighbor : graph[cur]) {
            if (neighbor == pre) {
                continue;
            }

            int depth = depth_Recursive(graph, neighbor, cur, diameter);
            if (depth1st < depth) {
                depth2nd = depth1st;
                depth1st = depth;
            }
            else if (depth2nd < depth){
                depth2nd = depth;
            }
        }

        diameter = max(diameter, depth1st + depth2nd);

        return depth1st + 1;
    }

    int treeDiameter(vector<vector<int>>& edges) {
        vector<set<int>> graph;
        for (const auto& edge : edges) {
            if (graph.size() <= edge[0]) {
                graph.resize(edge[0] + 1);
            }
            if (graph.size() <= edge[1]) {
                graph.resize(edge[1] + 1);
            }
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }

        int diameter = 0;
        depth_Recursive(graph, 0, -1, diameter);
        return diameter;
    }
};