class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        map<pair<int, int>, int> cnts;
        int ret = 0;
        for (const auto& coordinate : coordinates) {
            int x1 = coordinate[0], y1 = coordinate[1];
            for (int i = 0; i <= k; ++i) {
                int x2 = i ^ x1;
                int y2 = (k - i) ^ y1;
                ret += cnts[{x2, y2}];
            }
            ++cnts[{x1, y1}];
        }

        return ret;
    }
};
