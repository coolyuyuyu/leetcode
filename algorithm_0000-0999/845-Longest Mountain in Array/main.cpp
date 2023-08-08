class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();

        // dpLft[i]: the length of longest increasing sub-array ending at arr[i];
        vector<int> dpLft(n);
        dpLft[0] = 1;
        for (int i = 1; i < n; ++i) {
            if (arr[i - 1] < arr[i]) {
                dpLft[i] = dpLft[i - 1] + 1;
            }
            else {
                dpLft[i] = 1;
            }
        }

        // dpRht[i]: the length of longest increasing sub-array starting at arr[i];
        vector<int> dpRht(n);
        dpRht[n - 1] = 1;
        for (int i = n - 1; 1 < i--;) {
            if (arr[i] > arr[i + 1]) {
                dpRht[i] = dpRht[i + 1] + 1;
            }
            else {
                dpRht[i] = 1;
            }
        }

        int ret = 0;
        for (int i = 1; (i + 1) < n; ++i) {
            if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
                ret = std::max(ret, dpLft[i] + dpRht[i] - 1);
            }
        }

        return ret;
    }
};
