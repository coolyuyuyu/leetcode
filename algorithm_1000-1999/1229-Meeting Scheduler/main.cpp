class Solution {
public:
    vector<int> by2Pointers(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        std::sort(slots1.begin(), slots1.end());
        std::sort(slots2.begin(), slots2.end());

        int m = slots1.size(), n = slots2.size();
        for (int i = 0, j = 0; i < m && j < n;) {
            int bgn1 = slots1[i][0], end1 = slots1[i][1];
            int bgn2 = slots2[j][0], end2 = slots2[j][1];
            int bgn = std::max(bgn1, bgn2), end = std::min(end1, end2);
            if (end - bgn >= duration) {
                return {bgn, bgn + duration};
            }
            else if (end1 < end2) {
                ++i;
            }
            else {
                ++j;
            }
        }

        return {};
    }

    vector<int> byDiffArr(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        vector<pair<int, int>> pairs;
        for (const auto& slot : slots1) {
            pairs.emplace_back(slot[0], 1);
            pairs.emplace_back(slot[1], -1);
        }
        for (const auto& slot : slots2) {
            pairs.emplace_back(slot[0], 1);
            pairs.emplace_back(slot[1], -1);
        }
        std::sort(
            pairs.begin(), pairs.end(),
            [](const auto& p1, const auto p2) {
                const auto& [t1, diff1] = p1;
                const auto& [t2, diff2] = p2;
                return t1 < t2;
            });

        int sum = 0;
        int bgn;
        for (const auto& [t, diff] : pairs) {
            sum += diff;
            if (diff == 1 && sum == 2) {
                bgn = t;
            }
            else if (diff == -1 && sum == 1 && t - bgn >= duration) {
                return {bgn, bgn + duration};
            }
        }

        return {};
    }

    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        //return by2Pointers(slots1, slots2, duration);
        return byDiffArr(slots1, slots2, duration);
    }
};
