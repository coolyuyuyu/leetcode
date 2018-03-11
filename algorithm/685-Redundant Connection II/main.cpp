class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        static vector<int> EMPTY_EDGE;

        vector<int> parents(edges.size() + 1, 0);
        vector<int> chosenEdge;
        vector<int> unchosenEdge;
        for (size_t i = 0; i < edges.size(); ++i) {
            int parent = edges[i][0];
            int child = edges[i][1];
            if (parents[child] == 0) {
                parents[child] = parent;
            }
            else {
                chosenEdge = vector<int>{parents[child], child};
                unchosenEdge = vector<int>{parent, child};
            }
        }

        for (size_t i = 1; i < parents.size(); ++i) {
            parents[i] = i;
        }
        for (size_t i = 0; i < edges.size(); ++i) {
            if (edges[i] == unchosenEdge) {
                continue;
            }

            int parent = edges[i][0];
            int child = edges[i][1];
            int rootOfParent = parent;
            while (parents[rootOfParent] != rootOfParent) {
                rootOfParent = parents[rootOfParent];
            }
            if (rootOfParent == child) {
                if (chosenEdge == EMPTY_EDGE) {
                    return edges[i];
                }
                else {
                    return chosenEdge;
                }
            }

            parents[child] = parent;
        }

        return unchosenEdge;
    }
};