class Solution {
public:
    int bySort(int days, vector<vector<int>>& meetings) {
        std::sort(meetings.begin(), meetings.end());

        int ret = 0;
        int cur = 1;
        for (const auto& meeting : meetings) {
            int bgn = meeting[0], end = meeting[1];
            ret += std::max(0, bgn - cur);
            cur = std::max(cur, end + 1);
        }
        ret += days - cur + 1;

        return ret;
    }

    int byDiffArray(int days, vector<vector<int>>& meetings) {
        map<int, int> diffs;
        for (const auto& meeting : meetings) {
            int bgn = meeting[0], end = meeting[1];
            ++diffs[bgn];
            --diffs[end + 1];
        }
        ++diffs[days + 1];

        int ret = 0;
        int pre = 1, sum = 0;
        for (const auto& [cur, diff] : diffs) {
            if (sum == 0) {
                ret += cur - pre;
            }
            sum += diff;

            pre = cur;
        }

        return ret;
    }

    int countDays(int days, vector<vector<int>>& meetings) {
        //return bySort(days, meetings);
        return byDiffArray(days, meetings);
    }
};
