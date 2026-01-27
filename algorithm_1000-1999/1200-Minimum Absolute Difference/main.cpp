class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());

        vector<vector<int>> ret;
        for (int i = 0, n = arr.size(), minDiff = INT_MAX; i + 1 < n; ++i) {
            int diff = arr[i + 1] - arr[i];
            if (diff <= minDiff) {
                if (diff < minDiff) {
                    ret.clear();
                    minDiff = diff;
                }
                ret.push_back({arr[i], arr[i + 1]});
            }
        }

        return ret;
    }
};
