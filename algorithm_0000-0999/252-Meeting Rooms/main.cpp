class Solution {
public:
    // Time: O(n^2), Space: O(1)
    bool bruteforce(const vector<vector<int>>& intervals) {
        auto overlapped = [](const vector<int>& i1, const vector<int>& i2) -> bool {
            return i1[0] < i2[1] && i2[0] < i1[1];
        };
        for (size_t i = 0; i < intervals.size(); ++i) {
            for (size_t j = i + 1; j < intervals.size(); ++j) {
                if (overlapped(intervals[i], intervals[j])) {
                    return false;
                }
            }
        } 

        return true;
    }

    // Time: O(nlogn), Space(n)
    bool sweepline(const vector<vector<int>>& intervals) {
        map<int, int> m; // time -> diff
        for (const auto& interval : intervals) {
            ++m[interval[0]];
            --m[interval[1]];
        }

        int sum = 0;
        for (const auto [_, diff] : m) {
            sum += diff;
            if (1 < sum) {
                return false;
            }
        }

        return true;
    }

    // Time: O(nlogn), Space(1)
    bool sort(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const vector<int>& i1, const vector<int>& i2) { return i1[0] < i2[0]; });
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < intervals[i - 1][1]) {
                return false;
            }
        }

        return true;
    }

    bool canAttendMeetings(vector<vector<int>>& intervals) {
        //return bruteforce(intervals);
        //return sweepline(intervals);
        return sort(intervals);
    }
};
