class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> ret;
        for (const auto& interval : intervals) {
            int a = interval[0], b = interval[1];
            if (b <= toBeRemoved[0] || a >= toBeRemoved[1]) {
                ret.push_back(interval);
            }
            else {
                if (a < toBeRemoved[0]) {
                    ret.push_back({a, toBeRemoved[0]});
                }
                if (b > toBeRemoved[1]) {
                    ret.push_back({toBeRemoved[1], b});
                }
            }
        }

        return ret;
    }
};
