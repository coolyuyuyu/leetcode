class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, int> cnts;
        long long ret = 0;
        for (const auto& rect : rectangles) {
            int w = rect[0], h = rect[1];
            double ratio = 1.0 * w / h;
            ret += cnts[ratio];
            cnts[ratio] += 1;
        }

        return ret;
    }
};
