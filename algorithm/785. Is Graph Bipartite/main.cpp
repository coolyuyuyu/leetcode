class Solution {
public:
    bool isTwoColorable(const vector<vector<int>>& graph) {
        enum Color {Red, Green, Blank};
        vector<Color> colors(graph.size(), Blank);

        for (size_t node = 0; node < graph.size(); ++node) {
            if (colors[node] != Blank) {
                continue;
            }

            colors[node] = Red;
            queue<int> nodes;
            nodes.emplace(node);
            while (!nodes.empty()) {
                int node1 = nodes.front();
                nodes.pop();

                for (int node2 : graph[node1]) {
                    if (colors[node1] == colors[node2]) {
                        return false;
                    }
                    else if (colors[node2] == Blank) {
                        switch (colors[node1]) {
                            case Red:
                                colors[node2] = Green;
                                break;
                            case Green:
                                colors[node2] = Red;
                                break;
                        }
                        nodes.emplace(node2);
                    }
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        return isTwoColorable(graph);
    }
};