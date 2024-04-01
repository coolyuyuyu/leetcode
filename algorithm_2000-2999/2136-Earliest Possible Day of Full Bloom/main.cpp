class Solution {
public:
    int byBinarySearch(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();

        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; ++i) {
            pairs[i] = {plantTime[i], -growTime[i]};
        }
        std::sort(pairs.begin(), pairs.end(), [](const auto& p1, const auto& p2){ return p1.second < p2.second; });
        std::function<bool(int)> checkOk = [&](int t) {
            int x = 0;
            for (const auto& [pTime, gTime] : pairs) {
                x += pTime;
                if (x > t + gTime) {
                    return false;
                }
            }

            return true;
        };

        int lo = 1, hi = INT_MAX;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (checkOk(mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }

    int byGreedy(vector<int>& plantTime, vector<int>& growTime) {
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

    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        return byBinarySearch(plantTime, growTime);
        //return byGreedy(plantTime, growTime);
    }
};
