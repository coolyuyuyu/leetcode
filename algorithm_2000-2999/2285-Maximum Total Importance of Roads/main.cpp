class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        int degrees[n];
        std::fill(degrees, degrees + n, 0);

        for (const auto& road : roads) {
            int a = road[0], b = road[1];
            ++degrees[a];
            ++degrees[b];
        }
        std::sort(degrees, degrees + n);

        long long ret = 0;
        for (int i = 0; i < n; ++i) {
            ret += 1LL * degrees[i] * (i + 1);
        }

        return ret;
    }
};
