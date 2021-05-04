class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int minDiff = numeric_limits<int>::max();
        for (size_t i = 1; i < arr.size(); ++i) {
            int diff = arr[i] - arr[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
            }
        }

        vector<vector<int>> ret;
        for (size_t i = 1; i < arr.size(); ++i) {
            int diff = arr[i] - arr[i - 1];
            if ((arr[i] - arr[i - 1]) == minDiff) {
                ret.push_back({arr[i - 1], arr[i]});
            }
        }

        return ret;
    }
};
