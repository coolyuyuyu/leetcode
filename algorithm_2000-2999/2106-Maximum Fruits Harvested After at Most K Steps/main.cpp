class Solution {
public:
    int byTwoPointers(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();

        int presums[n];
        for (int i = 0; i < n; ++i) {
            presums[i] = (i > 0 ? presums[i - 1] : 0) + fruits[i][1];
        }

        int ret = 0;
        int mid;

        // A   S    B
        // <----
        // ---->
        //      ---->
        //  x     y
        mid = std::distance(fruits.begin(), std::lower_bound(fruits.begin(), fruits.end(), vector<int>{startPos, INT_MIN}));
        for (int i = 0, j = mid; j < n; ++j) { // for B
            while (fruits[i][0] <= startPos && 2 * (startPos - fruits[i][0]) + (fruits[j][0] - startPos) > k) {
                ++i;
            }

            if (fruits[i][0] <= startPos) {
                ret = std::max(ret, presums[j] - (i > 0 ? presums[i - 1] : 0));
            }
            else if (fruits[j][0] - startPos <= k) {
                ret = std::max(ret, presums[j] - (mid > 0 ? presums[mid - 1] : 0));
            }
        }

        // A   S    B
        //      ---->
        //      <----
        // <----
        //  x     y
        mid = std::distance(fruits.begin(), std::upper_bound(fruits.begin(), fruits.end(), vector<int>{startPos, INT_MAX})) - 1;
        for (int i = mid, j = n - 1; i >= 0; --i) { // for A
            while (startPos <= fruits[j][0] && (startPos - fruits[i][0]) + 2 * (fruits[j][0] - startPos) > k) {
                --j;
            }

            if (startPos <= fruits[j][0]) {
                ret = std::max(ret, presums[j] - (i > 0 ? presums[i - 1] : 0));
            }
            else if (startPos - fruits[i][0] <= k) {
                ret = std::max(ret, presums[mid] - (i > 0 ? presums[i - 1] : 0));
            }
        }

        return ret;
    }

    int byBSearch(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();

        int presums[n];
        for (int i = 0; i < n; ++i) {
            presums[i] = (i > 0 ? presums[i - 1] : 0) + fruits[i][1];
        }

        int ret = 0;
        int mid;

        // A   S    B
        // <----
        // ---->
        //      ---->
        //  x     y
        mid = std::distance(fruits.begin(), std::lower_bound(fruits.begin(), fruits.end(), vector<int>{startPos, INT_MIN}));
        for (int j = mid; j < n; ++j) { // for B
            if (fruits[j][0] - startPos > k) break;
            int d = (k - (fruits[j][0] - startPos)) / 2;
            int i = std::distance(fruits.begin(), std::lower_bound(fruits.begin(), fruits.end(), vector<int>{startPos - d, INT_MIN}));
            ret = std::max(ret, presums[j] - (i > 0 ? presums[i - 1] : 0));
        }

        // A   S    B
        //      ---->
        //      <----
        // <----
        //  x     y
        mid = std::distance(fruits.begin(), std::upper_bound(fruits.begin(), fruits.end(), vector<int>{startPos, INT_MAX})) - 1;
        for (int i = mid; i >= 0; --i) { // for A
            if (startPos - fruits[i][0] > k) break;
            int d = (k - (startPos - fruits[i][0])) / 2;
            int j = std::distance(fruits.begin(), std::upper_bound(fruits.begin(), fruits.end(), vector<int>{startPos + d, INT_MAX})) - 1;
            ret = std::max(ret, presums[j] - (i > 0 ? presums[i - 1] : 0));
        }

        return ret;
    }

    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        //eturn byTwoPointers(fruits, startPos, k);
        return byBSearch(fruits, startPos, k);
    }
};
