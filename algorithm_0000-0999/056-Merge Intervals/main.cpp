class Solution {
public:
    // Time: O(n), Space: O(1)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int, int>> diffs;
        for (const auto& interval : intervals) {
            diffs.push_back({interval[0], 1});
            diffs.push_back({interval[1], -1});
        }

        auto comp = [](const pair<int, int>& diff1, const pair<int, int>& diff2) {
            return diff1.first < diff2.first || (diff1.first == diff2.first && diff1.second > diff2.second);
        };
        std::sort(diffs.begin(), diffs.end(), comp);

        intervals.clear();

        int sum = 0;
        int start, end;
        for (auto [index, diff] : diffs) {
            if (sum == 0 && 0 < diff) {
                start = index;
            }
            else if (0 < sum && (sum + diff) == 0) {
                end = index;
                intervals.push_back({start, end});
            }
            sum += diff;
        }

        return intervals;
    }
};
