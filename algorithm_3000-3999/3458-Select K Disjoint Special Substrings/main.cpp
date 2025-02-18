class Solution {
public:
    bool maxSubstringLength(string s, int k) {
        vector<pair<int, int>> boundaries(26, {-1, -1});
        for (int i = 0; i < s.size(); ++i) {
            auto& [lft, rht] = boundaries[s[i] - 'a'];
            if (lft == -1) {
                lft = i, rht = i;
            }
            else {
                rht = i;
            }
        }

        vector<pair<int, int>> intervals;
        for (auto [lft, rht] : boundaries) {
            if (lft == -1) { continue; }
            bool valid = true;
            for (int i = lft ; i <= rht; ++i) {
                if (boundaries[s[i] - 'a'].first < lft) {
                    valid = false;
                    break;
                }
                rht = std::max(rht, boundaries[s[i] - 'a'].second);
            }
            if (rht - lft + 1 == s.size()) { continue; }
            if (valid) {
                intervals.emplace_back(lft, rht);
            }
        }

        std::sort(intervals.begin(), intervals.end(), [](const auto& i1, const auto& i2) { return i1.second < i2.second; });
        int cnt = 0;
        for (int i = 0, rht = INT_MIN; i < intervals.size(); ++i) {
            if (rht < intervals[i].first) {
                ++cnt;
                rht = intervals[i].second;
            }
        }

        return cnt >= k;
    }
};
