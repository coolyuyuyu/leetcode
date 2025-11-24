class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        std::sort(
            intervals.begin(), intervals.end(),
            [&](const auto& i1, const auto& i2){
                return i1[1] < i2[1] || (i1[1] == i2[1] && i1[0] > i2[0]);
            });

        int a = INT_MIN, b = INT_MIN + 1;
        int ret = 0;
        for (const auto& interval : intervals) {
            if (a >= interval[0]) { continue; }
            if (b >= interval[0]) {
                ret += 1;
                a = b;
                b = interval[1];
            }
            else {
                a = interval[1] - 1, b = interval[1];
                ret += 2;
            }
        }

        return ret;
    }
};
