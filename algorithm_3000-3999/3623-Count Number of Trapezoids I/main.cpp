class Solution {
public:
    int M = 1e9 + 7;

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> y2PntCnt;
        for (const auto& point : points) {
            int x = point[0], y = point[1];
            ++y2PntCnt[y];
        }

        int ret = 0; int sum = 0;
        for (const auto& [_, pntCnt] : y2PntCnt) {
            int edgeCnt = (1LL * pntCnt * (pntCnt - 1) / 2) % M;
            ret += (1LL * edgeCnt * sum) % M;
            ret %= M;
            sum += edgeCnt;
            sum %= M;
        }

        return ret;
    }
};
