class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto comp = [](const vector<int>& i1, const vector<int>& i2) {
            return i1[1] < i2[1];
        };
        std::sort(intervals.begin(), intervals.end(), comp);

        int ans = 0;
        for (size_t pre = 0, cur = 1; cur < intervals.size(); ++cur) {
            if (intervals[cur][0] < intervals[pre][1]) { // overlap
                ++ans;
            }
            else {
                pre = cur;
            }
        }

        return ans;
    }
};
