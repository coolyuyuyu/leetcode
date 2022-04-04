class Solution {
public:
    vector<int> getRow_BruteForce(int rowIndex) {
        vector<int> row = {1};
        for (; 0 < rowIndex; --rowIndex) {
            vector<int> tmpRow;
            tmpRow.push_back(1);
            for (size_t i = 1; i < row.size(); ++i) {
                tmpRow.push_back(row[i - 1] + row[i]);
            }
            tmpRow.push_back(1);

            row.swap(tmpRow);
        }

        return row;
    }

    vector<int> getRow_Math(int rowIndex) {
        vector<int> row = {1};
        for (int k = 1; k <= rowIndex; ++k) {
            row.push_back(static_cast<long long int>(row.back()) * (rowIndex - k + 1) / k);
        }

        return row;
    }

    vector<int> getRow(int rowIndex) {
        //return getRow_BruteForce(rowIndex);
        return getRow_Math(rowIndex);
    }
};
