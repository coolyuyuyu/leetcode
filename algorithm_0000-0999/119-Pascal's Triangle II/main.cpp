class Solution {
public:
    vector<int> dp(size_t rowIndex) {
        if (rowIndex == 0) {
            return {1};
        }

        vector<int> ret = {1};
        for (size_t i = 1; i <= rowIndex; ++i) {
            vector<int> tmp;
            tmp.resize(i + 1);

            tmp[0] = 1;
            for (size_t j = 1; j < i; ++j) {
                tmp[j] = ret[j - 1] + ret[j];
            }
            tmp[i] = 1;

            std::swap(ret, tmp);
        }

        return ret;
    }


    vector<int> math(size_t rowIndex) {
        if (rowIndex == 0) {
            return {1};
        }

        vector<int> ret(rowIndex + 1);
        ret[0] = 1;
        for (size_t k = 1; k < rowIndex; ++k) {
            ret[k] = ret[k - 1] * (rowIndex - k + 1) / k;
        }
        ret[rowIndex] = 1;

        return ret;
    }

    vector<int> getRow(int rowIndex) {
        //return dp(rowIndex);
        return math(rowIndex);
    }
};