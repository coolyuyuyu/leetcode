
class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if (M.empty()) {
            return 0;
        }

        int result = 0;

        int width = M.front().size();
        int length = M.size();

        // horizontal
        for (int i = 0; i < length; ++i) {
            int subResult = 0;
            for (int j = 0; j < width; ++j) {
                if (M[i][j]) {
                    ++subResult;
                    result = max(result, subResult);
                }
                else {
                    subResult = 0;
                }
            }
        }

        // vertical
        for (int i = 0; i < width; ++i) {
            int subResult = 0;
            for (int j = 0; j < length; ++j) {
                if (M[j][i]) {
                    ++subResult;
                    result = max(result, subResult);
                }
                else {
                    subResult = 0;
                }
            }
        }

        //diagonal
        for (int x = 0; x < width; ++x) {
            int i = 0;
            int j = x;
            int subResult = 0;
            do {
                if (M[i][j]) {
                    ++subResult;
                    result = max(result, subResult);
                }
                else {
                    subResult = 0;
                }
                ++i; ++j;
            } while (i < length && j < width);
        }
        for (int x = 0; x < length; ++x) {
            int i = x;
            int j = 0;
            int subResult = 0;
            do {
                if (M[i][j]) {
                    ++subResult;
                    result = max(result, subResult);
                }
                else {
                    subResult = 0;
                }
                ++i; ++j;
            } while (i < length && j < width);
        }

        //anti-diagonal
        for (int x = width - 1; 0 <= x; --x) {
            int i = 0;
            int j = x;
            int subResult = 0;
            do {
                if (M[i][j]) {
                    ++subResult;
                    result = max(result, subResult);
                }
                else {
                    subResult = 0;
                }
                ++i; --j;
            } while (i < length && 0 <= j);
        }
        for (int x = 0; x < length; ++x) {
            int i = x;
            int j = width - 1;
            int subResult = 0;
            do {
                if (M[i][j]) {
                    ++subResult;
                    result = max(result, subResult);
                }
                else {
                    subResult = 0;
                }
                ++i; --j;
            } while (i < length && 0 <= j);
        }

        return result;
    }
};