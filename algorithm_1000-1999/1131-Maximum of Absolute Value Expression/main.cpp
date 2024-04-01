class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        vector<array<int, 3>> vecs(n);
        for (int i = 0; i < n; ++i) {
            vecs[i] = {arr1[i], arr2[i], i};
        }

        int ret = INT_MIN;
        for (int state = 0; state < (1 << 3); ++state) {
            int minVal = INT_MAX, maxVal = INT_MIN;
            for (const auto& vec: vecs) {
                int val = 0;
                for (int j = 0; j < 3; ++j) {
                    val += ((state & (1 << j)) ? +1 : -1) * vec[j];
                }

                minVal = std::min(minVal, val);
                maxVal = std::max(maxVal, val);
            }

            ret = std::max(ret, maxVal - minVal);
        }

        return ret;
    }
};
