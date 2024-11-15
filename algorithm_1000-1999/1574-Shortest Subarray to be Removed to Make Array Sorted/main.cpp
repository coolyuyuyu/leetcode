class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();

        int j = n - 1;
        while (0 < j && arr[j - 1] <= arr[j]) {
            --j;
        }

        int ret = j;
        if (ret == 0) {
            return 0;
        }

        for (int i = 0; i < n; ++i) {
            if (0 < i && arr[i - 1] > arr[i]) { break; };
            while (j < n && arr[i] > arr[j]) {
                ++j;
            }
            ret = std::min(ret, j - i - 1);
        }

        return ret;
    }
};
