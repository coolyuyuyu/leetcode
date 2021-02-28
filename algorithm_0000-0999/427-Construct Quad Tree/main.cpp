/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* constructHelper(int row, int col, int len, vector<vector<int>>& grid) {
        if (len <= 1) {
            return new Node(grid[row][col], true, nullptr, nullptr, nullptr, nullptr);
        }

        bool isLeaf = true;
        for (size_t r = row; r < row + len && isLeaf; ++r) {
            for (size_t c = col; c < col + len; ++c) {
                if (grid[r][c] != grid[row][col]) {
                    isLeaf = false;
                    break;
                }
            }
        }

        if (isLeaf) {
            return new Node(grid[row][col], true, nullptr, nullptr, nullptr, nullptr);
        }

        Node* node = new Node(
                            false,
                            false,
                            constructHelper(row, col, len / 2, grid),
                            constructHelper(row, col + len / 2, len / 2, grid),
                            constructHelper(row + len / 2, col, len / 2, grid),
                            constructHelper(row + len / 2, col + len / 2, len / 2, grid));
        return node;
    }

    Node* construct(vector<vector<int>>& grid) {
        return constructHelper(0, 0, grid.size(), grid);
    }
};