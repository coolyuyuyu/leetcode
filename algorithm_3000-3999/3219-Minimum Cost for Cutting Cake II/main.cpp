class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        auto& hCuts = horizontalCut;
        std::sort(hCuts.rbegin(), hCuts.rend());
        auto& vCuts = verticalCut;
        std::sort(vCuts.rbegin(), vCuts.rend());
        int i = 0, j = 0;
        long long ret = 0;
        while (i < m - 1 && j < n - 1) {
            if (hCuts[i] > vCuts[j]) {
                ret += hCuts[i] * (j + 1);
                ++i;
            }
            else {
                ret += vCuts[j] * (i + 1);
                ++j;
            }
        }
        while (i < m - 1) {
            ret += hCuts[i] * (j + 1);
            ++i;
        }
        while (j < n - 1) {
            ret += vCuts[j] * (i + 1);
            ++j;
        }

        return ret;
    }
};
