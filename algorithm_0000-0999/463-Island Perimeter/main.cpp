class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int primeter = 0;
        int width = grid.front().size();
        int length = grid.size();        
        for (int i = 0; i < length; ++i) {
            vector<int>& row = grid[i];
            for (int j = 0; j < width; ++j) {
                if (grid[i][j]) {
                    primeter += 4;

                    if (0 < i && grid[i - 1][j]) {
                        primeter -= 2;
                    }

                    if (0 < j && grid[i][j - 1]) {
                        primeter -= 2;
                    }
                }
            }
        }

        return primeter;
    }
};