class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int n = points.size();

        pair<int, char> arr[n];
        for (int i = 0; i < n; ++i) {
            int x = points[i][0], y = points[i][1];
            char c = s[i];
            arr[i] = {std::max(std::abs(x), std::abs(y)), c};
        }
        std::sort(
            arr, arr + n,
            [](const auto& e1, const auto& e2) {
                return e1.first < e2.first;
            });

        vector<bool> visited(26, false);
        for (int i = 0; i < n;) {
            int j;
            for (j = i; j < n && arr[j].first == arr[i].first; ++j) {
                if (visited[arr[j].second - 'a']) {
                    return i;
                }
                visited[arr[j].second - 'a'] = true;
            }
            i = j;
        }

        return n;
    }
};
