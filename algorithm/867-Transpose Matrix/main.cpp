class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        size_t rowCnt = A.size(), colCnt = A.front().size(); 
        auto const minmax = std::minmax(rowCnt, colCnt);

        if (rowCnt < colCnt) {
            for (size_t i = rowCnt; i < colCnt; ++i) {
                A.push_back(vector<int>(rowCnt));
            }
        }
        else if (rowCnt > colCnt) {
            for (size_t i = 0; i < colCnt; ++i) {
                A[i].resize(rowCnt);
            }
        }
        
        for (size_t i = 0; i < minmax.first; ++i) {
            for (size_t j = i + 1; j < minmax.second; ++j) {
                swap(A[i][j], A[j][i]);
            }
        }

        A.resize(colCnt);
        for (size_t i = 0; i < colCnt; ++i) {
            A[i].resize(rowCnt);
        }

        return A;
    }
};