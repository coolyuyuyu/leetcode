class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        int n = points.size();

        vector<multiset<int>> arr(4);
        for (const auto& point: points) {
            int x = point[0], y = point[1];

            arr[0].insert(0 + x + y);
            arr[1].insert(0 + x - y);
            arr[2].insert(0 - x + y);
            arr[3].insert(0 - x - y);
        }

        int ret = INT_MAX;
        for (const auto& point: points) {
            int x = point[0], y = point[1];

            arr[0].erase(arr[0].find(0 + x + y));
            arr[1].erase(arr[1].find(0 + x - y));
            arr[2].erase(arr[2].find(0 - x + y));
            arr[3].erase(arr[3].find(0 - x - y));

            int maxManhattan = INT_MIN;
            maxManhattan = std::max(maxManhattan, *arr[0].rbegin() - *arr[0].begin());
            maxManhattan = std::max(maxManhattan, *arr[1].rbegin() - *arr[1].begin());
            maxManhattan = std::max(maxManhattan, *arr[2].rbegin() - *arr[2].begin());
            maxManhattan = std::max(maxManhattan, *arr[3].rbegin() - *arr[3].begin());
            ret = std::min(ret, maxManhattan);

            arr[0].insert(0 + x + y);
            arr[1].insert(0 + x - y);
            arr[2].insert(0 - x + y);
            arr[3].insert(0 - x - y);
        }

        return ret;
    }
};
