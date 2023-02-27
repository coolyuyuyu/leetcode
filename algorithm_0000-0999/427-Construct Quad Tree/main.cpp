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

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

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
    Node* construct(const vector<vector<int>>& grid, int r, int c, int len) {
        for (int i = r; i < (r + len); ++i) {
            for (int j = c; j < (c + len); ++j) {
                if (grid[r][c] != grid[i][j]) {
                    return new Node(
                        false,
                        false,
                        construct(grid, r, c, len / 2),
                        construct(grid, r, c + len / 2, len / 2),
                        construct(grid, r + len / 2, c, len / 2),
                        construct(grid, r + len / 2, c + len / 2, len / 2));
                }
            }
        }

        return new Node(grid[r][c], true);
    }

    Node* construct(vector<vector<int>>& grid) {
        return construct(grid, 0, 0, grid.size());
    }
};
