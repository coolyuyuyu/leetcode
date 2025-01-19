class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        int n = arr.size();

        long long ret1 = 0;
        for (int i = 0; i < n; ++i) {
            ret1 += std::abs(arr[i] - brr[i]);
        }

        long long ret2 = k;
        std::sort(arr.begin(), arr.end());
        std::sort(brr.begin(), brr.end());
        for (int i = 0; i < n; ++i) {
            ret2 += std::abs(arr[i] - brr[i]);
        }

        return std::min(ret1, ret2);
    }
};
