class Solution {
public:
    vector<int> getRow_BruteForce(size_t rowIndex) {
        vector<int> row = {1};
        for (; 0 < rowIndex; -- rowIndex) {
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

    vector<int> getRow(int rowIndex) {
        return getRow_BruteForce(rowIndex);
    }
};
