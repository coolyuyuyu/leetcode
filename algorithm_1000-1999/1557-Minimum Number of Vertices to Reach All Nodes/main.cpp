class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> reachables(n, false);
        for (const auto& edge : edges) {
            reachables[edge[1]] = true;
        }

        vector<int> ret;
        for (int i = 0; i < n; ++i) {
            if (!reachables[i]) {
                ret.push_back(i);
            }
        }

        return ret;
    }
};
