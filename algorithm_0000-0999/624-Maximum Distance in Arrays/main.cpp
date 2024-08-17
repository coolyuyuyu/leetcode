class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mn = INT_MAX / 2, mx = INT_MIN / 2;
        int ret = 0;
        for (const auto& arr : arrays) {
            ret = std::max({ret, arr.back() - mn, mx - arr.front()});
            mn = std::min(mn, arr.front());
            mx = std::max(mx, arr.back());
        }

        return ret;
    }
};
