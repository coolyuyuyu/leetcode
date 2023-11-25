class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        for (int i = 0; i < n; ++i) {
            intervals[i].push_back(i);
        }

        std::sort(intervals.begin(), intervals.end(), [](const auto& t1, const auto& t2){ return t1[0] < t2[0]; });

        vector<int> ret(n);
        for (int i = 0; i < n; ++i) {
            auto itr = std::lower_bound(
                intervals.begin(), intervals.end(),
                vector<int>{intervals[i][1],0, 0},
                [](const auto& t1, const auto& t2){ return t1[0] < t2[0]; });
            if (itr != intervals.end()) {
                ret[intervals[i][2]] = itr->at(2);
            }
            else {
                ret[intervals[i][2]] = -1;
            }
        }

        return ret;
    }
};
