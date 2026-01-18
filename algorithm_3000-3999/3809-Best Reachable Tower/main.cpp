class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        vector<int> ret = {-1, -1};
        int qMax = INT_MIN;
        for (const auto& tower : towers) {
            int x = tower[0], y = tower[1], q = tower[2];
            int dist = std::abs(x - center[0]) + std::abs(y - center[1]);
            if (dist <= radius) {
                if (q > qMax) {
                    ret = {x, y};
                    qMax = q;
                }
                else if (q == qMax) {
                    ret = std::min(ret, vector<int>{x, y});
                }
            }
        }

        return ret;
    }
};
