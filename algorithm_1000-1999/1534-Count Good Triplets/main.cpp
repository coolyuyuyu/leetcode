class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int cnt = 0;
        for (size_t i = 0; (i + 2) < arr.size(); ++i) {
            for (size_t j = i + 1; (j + 1) < arr.size(); ++j) {
                if (a < abs(arr[i] - arr[j])) {
                    continue;
                }
                for (size_t k = j + 1; k < arr.size(); ++k) {
                    if (abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
                        ++cnt;
                    }
                }
            }
        }

        return cnt;
    }
};
