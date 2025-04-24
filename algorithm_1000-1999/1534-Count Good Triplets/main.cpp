class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int ret = 0;
        for (int i = 0, n = arr.size(); i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (std::abs(arr[i] - arr[j]) > a) { continue; }
                for (int k = j + 1; k < n; ++k) {
                    if (std::abs(arr[j] - arr[k]) > b) { continue; }
                    if (std::abs(arr[i] - arr[k]) > c) { continue; }
                    ++ret;
                }
            }
        }

        return ret;
    }
};
