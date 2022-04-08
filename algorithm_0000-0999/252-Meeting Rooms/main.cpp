class Solution {
public:
    // Time: O(N^2)
    bool canAttendMeetings_BruteForce(vector<vector<int>>& intervals) {
        for (size_t i = 0; i < intervals.size(); ++i) {
            for (size_t j = i + 1; j < intervals.size(); ++j) {
                if (intervals[j][0] < intervals[i][1] && intervals[i][0] < intervals[j][1]) {
                    return false;
                }
            }
        }

        return true;
    }

    // Time: O(NlogN)
    bool canAttendMeetings_Sort(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        for (size_t i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < intervals[i - 1][1]) {
                return false;
            }
        }

        return true;
    }

    bool canAttendMeetings(vector<vector<int>>& intervals) {
        //return canAttendMeetings_BruteForce(intervals);
        return canAttendMeetings_Sort(intervals);
    }
};
