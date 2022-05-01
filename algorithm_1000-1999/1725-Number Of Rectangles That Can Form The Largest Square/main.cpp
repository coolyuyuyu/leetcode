class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        size_t cnt = 0;
        size_t maxLen = 0;
        for (const auto& rect : rectangles) {
            int len = std::min(rect[0], rect[1]);
            if (maxLen < len) {
                maxLen = len;
                cnt = 1;
            }
            else if (maxLen == len) {
                ++cnt;
            }
        }

        return cnt;
    }
};
