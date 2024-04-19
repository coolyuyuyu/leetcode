class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        int n = logs.size();
        std::sort(logs.begin(), logs.end());

        vector<int> ret(k, 0);
        for (int i = 0; i < n;) {
            int j = i + 1;
            int cnt = 1;
            for (; j < n && logs[i][0] == logs[j][0]; ++j) {
                if (logs[j - 1][1] < logs[j][1]) {
                    ++cnt;
                }
            }
            if (cnt <= k) {
                ++ret[cnt - 1];
            }
            i = j;
        }

        return ret;
    }
};
