class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parents(edges.size());
        for (size_t i = 0; i < parents.size(); ++i) {
            parents[i] = i;
        }

        for (size_t i = 0; i < edges.size(); ++i) {
            const vector<int>& edge = edges[i];

            int a = edge[0] - 1;
            int parentA = a;
            while (parentA != parents[parentA]) {
                parentA = parents[parentA];
            }
            int b = edge[1] - 1;
            int parentB = b;
            while (parentB != parents[parentB]) {
                parentB = parents[parentB];
            }

            if (parentA == parentB) {
                return vector<int>{a+1, b+1};
            }
            else {
                parents[parentA] = parentB;
            }
        }

        assert(false);
        return vector<int>();
    }
};