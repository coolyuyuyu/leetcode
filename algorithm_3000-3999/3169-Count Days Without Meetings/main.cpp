class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        std::sort(meetings.begin(), meetings.end());

        int cur = 1, ret = 0;
        for (const auto& meeting : meetings) {
            int bgn = meeting[0], end = meeting[1];
            ret += std::max(0, meeting[0] - cur);
            cur = std::max(cur, meeting[1] + 1);
        }
        ret += days - cur + 1;

        return ret;
    }
};
