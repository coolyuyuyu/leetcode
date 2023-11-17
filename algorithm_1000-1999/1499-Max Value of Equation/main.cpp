class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();

        deque<int> dq;

        int ret = INT_MIN;
        for (int j = 0; j < n; ++j) {
            // max(yi + yj + |xi - xj|), i < j
            // => max(yi + yj + -xi + xj), i < j
            // => for each j, xj + yj + max(-xi + yi)

            while (!dq.empty() && points[j][0] - points[dq.front()][0] > k) {
                dq.pop_front();
            }
            if (!dq.empty()) {
                int i = dq.front();
                ret = std::max(ret, points[j][0] + points[j][1] - points[i][0] + points[i][1]);
            }
            while (!dq.empty() && -points[dq.back()][0] + points[dq.back()][1] <= -points[j][0] + points[j][1]) {
                dq.pop_back();
            }

            dq.push_back(j);
        }

        return ret;
    }
};
