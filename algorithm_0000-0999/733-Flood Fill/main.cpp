class Solution {
public:

    void floodFill_DfsRecursiveHelper(vector<vector<int>>& image, const std::pair<int, int>& pos, int oldColor, int newColor) {
        int r = pos.first, c = pos.second;
        if (image[r][c] == oldColor) {
            image[r][c] = newColor;

            if (0 < c) { // left
                floodFill_DfsRecursiveHelper(image, {r, c - 1}, oldColor, newColor);
            }
            if (0 < r) { // top
                floodFill_DfsRecursiveHelper(image, {r - 1, c}, oldColor, newColor);
            }
            if ((c + 1) < image.front().size()) { // right
                floodFill_DfsRecursiveHelper(image, {r, c + 1}, oldColor, newColor);
            }
            if ((r + 1) < image.size()) { // bottom
                floodFill_DfsRecursiveHelper(image, {r + 1, c}, oldColor, newColor);
            }
        }
    }

    void floodFill_DfsRecursive(vector<vector<int>>& image, int r, int c, int newColor) {
        if (image[r][c] != newColor) {
            floodFill_DfsRecursiveHelper(image, {r, c}, image[r][c], newColor);
        }
    }

    void floodFill_DfsIterative(vector<vector<int>>& image, int r, int c, int newColor) {
        int oldColor = image[r][c];
        if (oldColor == newColor) {
            return;
        }

        stack<pair<int, int>> stk({{r, c}});
        while (!stk.empty()) {
            int r = stk.top().first, c = stk.top().second;
            stk.pop();

            if (image[r][c] == oldColor) {
                image[r][c] = newColor;

                if (0 < c) { // left
                    stk.push({r, c - 1});
                }
                if (0 < r) { // top
                    stk.push({r - 1, c});
                }
                if ((c + 1) < image.front().size()) { // right
                    stk.push({r, c + 1});
                }
                if ((r + 1) < image.size()) { // bottom
                    stk.push({r + 1, c});
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        //floodFill_DfsRecursive(image, sr, sc, newColor);
        floodFill_DfsIterative(image, sr, sc, newColor);
        return image;
    }
};
