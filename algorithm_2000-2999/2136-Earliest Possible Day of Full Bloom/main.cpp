class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();

        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; ++i) {
            pairs[i] = {plantTime[i], growTime[i]};
        }
        std::sort(pairs.begin(), pairs.end(), [](const auto& p1, const auto& p2){ return p1.second > p2.second; });

        int ret = 0;

        int t = 0;
        for (int i = 0; i < n; ++i) {
            const auto& [pTime, gTime] = pairs[i];
            t += pTime;
            ret = std::max(ret, t + gTime);
        }

        return ret;
    }
};
