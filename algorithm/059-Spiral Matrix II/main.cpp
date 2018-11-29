class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<pair<int, int>> deltas = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        size_t deltaIndex = 0;

        int x = 0, y = 0;
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for (int i = 1; i <= n * n; ++i) {
            ans[x][y] = i;
            
            int newX = x + deltas[deltaIndex].first;
            int newY = y + deltas[deltaIndex].second;
            if (newX < 0 || newX >= n || newY < 0 || newY >= n || ans[newX][newY] != 0) {
                deltaIndex = (deltaIndex + 1) % 4;
                newX = x + deltas[deltaIndex].first;
                newY = y + deltas[deltaIndex].second;
            }

            x = newX;
            y = newY;
        }

        return ans;
    }
};