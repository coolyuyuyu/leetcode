class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();

        int a, b;

        vector<bool> used(n * n + 1, false);
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (used[grid[r][c]]) {
                    a = grid[r][c];
                }
                used[grid[r][c]] = true;
            }
        }

        for (int i = 1; i < used.size(); ++i) {
            if (!used[i]) {
                b = i;
                break;
            }
        }

        return {a, b};
    }
};
