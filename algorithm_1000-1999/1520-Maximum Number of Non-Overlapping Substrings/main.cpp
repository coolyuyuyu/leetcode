class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
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
            if (valid) {
                intervals.emplace_back(lft, rht);
            }
        }

        std::sort(intervals.begin(), intervals.end(), [](const auto& i1, const auto& i2) { return i1.second - i1.first < i2.second - i2.first; });

        vector<bool> flags(intervals.size(), true);
        for (int i = 0; i < intervals.size(); ++i) {
            if (flags[i] == false) { continue; }
            const auto& [lft1, rht1] = intervals[i];
            for (int j = i + 1; j < intervals.size(); ++j) {
                if (flags[j] == false) { continue; }
                const auto& [lft2, rht2] = intervals[j];
                if (lft2 < lft1 && rht1 < rht2) {
                    flags[j] = false;
                }
            }
        }

        vector<string> ret;
        for (int i = 0; i < intervals.size(); ++i) {
            if (flags[i] == false) { continue; }
            const auto& [lft, rht] = intervals[i];
            ret.push_back(s.substr(lft, rht - lft + 1));
        }

        return ret;
    }
};
