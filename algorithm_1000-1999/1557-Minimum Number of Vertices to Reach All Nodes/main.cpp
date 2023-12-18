class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        bool in[n];
        std::fill(in, in + n, false);
        for (const auto& edge : edges) {
            in[edge[1]] = true;
        }

        vector<int> ret;
        for (int i = 0; i < n; ++i) {
            if (!in[i]) {
                ret.push_back(i);
            }
        }

        return ret;
    }
};
