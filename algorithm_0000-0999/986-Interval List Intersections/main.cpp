class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        const vector<vector<int>>& l1 = firstList;
        const vector<vector<int>>& l2 = secondList;

        vector<vector<int>> ret;
        for (int i = 0, j = 0, m = l1.size(), n = l2.size(); i < m && j < n;) {
            int minVal = std::max(l1[i][0], l2[j][0]);
            int maxVal = std::min(l1[i][1], l2[j][1]);
            if (minVal <= maxVal) {
                ret.push_back({minVal, maxVal});
            }

            if (l1[i][1] <= l2[j][1]) {
                ++i;
            }
            else {
                ++j;
            }
        }

        return ret;
    }
};
