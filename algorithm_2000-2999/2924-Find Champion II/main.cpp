class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int in[n];
        std::fill(in, in + n, 0);

        for (const auto& edge : edges) {
            ++in[edge[1]];
        }

        int cnt0 = 0, champ = -1;
        for (int i = 0; i < n; ++i) {
            if (in[i] == 0) {
                ++cnt0;
                champ = i;
            }
        }

        return cnt0 == 1 ? champ : -1;
    }
};
