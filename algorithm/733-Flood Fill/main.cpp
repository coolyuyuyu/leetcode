class Solution {
public:
    void dfs(vector<vector<int>>& image, int row, int col, int color, int newColor) {
        if (image[row][col] == newColor) {
            return;
        }

        if (image[row][col] == color) {
            image[row][col] = newColor;
            if (col > 0) {
                dfs(image, row, col - 1, color, newColor);
            }
            if (row > 0) {
                dfs(image, row - 1, col, color, newColor);
            }
            if (col + 1 < image.front().size()) {
                dfs(image, row, col + 1, color, newColor);
            }
            if (row + 1 < image.size()) {
                dfs(image, row + 1, col, color, newColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
};
