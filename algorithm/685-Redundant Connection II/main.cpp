class Solution {
public:
    void makeSet(vector<int>& parents) {
        for (size_t i = 1; i < parents.size(); ++i) {
            parents[i] = i;
        }
    }

    int find(vector<int>& parents, int i) {
        if (parents[i] != i) {
            parents[i] = find(parents, parents[i]);
        }

        return parents[i];
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> parents(edges.size() + 1);
        makeSet(parents);

        // identify two parents point to the same child.
        static vector<int> EMPTY_EDGE = {0, 0};
        vector<int> chosenEdge = EMPTY_EDGE, removedEdge = EMPTY_EDGE;
        for (auto edge : edges) {
            int parent = edge[0], child = edge[1];
            if (parents[child] == child) {
                parents[child] = parent;
            }
            else {
                removedEdge = edge;
                chosenEdge = {parents[child], child};
            }
        }

        makeSet(parents);
        for (auto edge : edges) {
            if (edge == removedEdge) {
                continue;
            }

            int parent = edge[0], child = edge[1];
            int rootParent = find(parents, parent);
            if (rootParent == child) {
                if (chosenEdge == EMPTY_EDGE) {
                    return edge;
                }
                else {
                    return chosenEdge;
                }
            }

            parents[child] = rootParent;
        }

        return removedEdge;
    }
};