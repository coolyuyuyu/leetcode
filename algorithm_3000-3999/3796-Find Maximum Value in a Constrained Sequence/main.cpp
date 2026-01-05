class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        vector<int> a(n, INT_MAX);
        a[0] = 0;
        for (const auto& restriction : restrictions) {
            int idx = restriction[0], maxVal = restriction[1];
            a[idx] = maxVal;
        }

        for (int i = 1; i < n; ++i) {
            a[i] = std::min(a[i], a[i - 1] + diff[i - 1]);
        }

        for (int i = n - 2; i >= 0; --i) {
            a[i] = std::min(a[i], a[i + 1] + diff[i]);
        }

        return *std::max_element(a.begin(), a.end());
    }
};
