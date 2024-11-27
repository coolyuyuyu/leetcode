class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int in[n];
        std::fill(in, in + n, 0);

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            ++in[v];
        }

        int cnt0 = 0, ret = -1;
        for (int i = 0; i < n; ++i) {
            if (in[i] == 0) {
                ++cnt0;
                ret = i;
            }
        }

        return cnt == 1 ? ret : -1;
    }
};
