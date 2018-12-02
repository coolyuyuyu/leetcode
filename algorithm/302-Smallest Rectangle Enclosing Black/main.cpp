class Solution {
public:
    void minAriaHelper(vector<vector<char>>& image, int x, int y, int& minX, int& minY, int& maxX, int& maxY) {
        if (image[x][y] == '0') {
            return;
        }

        image[x][y] = '0';

        minX = min(minX, x);
        minY = min(minY, y);
        maxX = max(maxX, x);
        maxY = max(maxY, y);

        // lft
        if (0 < y) {
            minAriaHelper(image, x, y - 1, minX, minY, maxX, maxY);
        }

        // top
        if (0 < x) {
            minAriaHelper(image, x - 1, y, minX, minY, maxX, maxY);
        }

        // rht
        if (y + 1 < image.front().size()) {
            minAriaHelper(image, x, y + 1, minX, minY, maxX, maxY);
        }

        // btm
        if (x + 1 < image.size()) {
            minAriaHelper(image, x + 1, y, minX, minY, maxX, maxY);
        }
    }

    int minArea(vector<vector<char>>& image, int x, int y) {
        int minX = x, minY = y;
        int maxX = x, maxY = y;
        minAriaHelper(image, x, y, minX, minY, maxX, maxY);
        return (maxX - minX + 1) * (maxY - minY + 1);
    }
};