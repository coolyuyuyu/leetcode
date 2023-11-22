class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mn = INT_MAX / 2, mx = INT_MIN / 2;
        int ret = 0;
        for (const auto& array : arrays) {
            ret = std::max({ret, mx - array.front(), array.back() - mn});
            mn = std::min(mn, array.front());
            mx = std::max(mx, array.back());
        }

        return ret;
    }
};
