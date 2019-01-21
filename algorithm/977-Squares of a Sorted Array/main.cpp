class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> squares(A.size());
        for (size_t front = 0, back = A.size(), index = squares.size(); front < back;) {
            int squareFront = A[front] * A[front];
            int squareBack = A[back - 1] * A[back - 1];
            if (squareFront <= squareBack) {
                squares[index - 1] = squareBack;
                --back;
            }
            else {
                squares[index - 1] = squareFront;
                ++front;
            }
            --index;
        }

        return squares;
    }
};