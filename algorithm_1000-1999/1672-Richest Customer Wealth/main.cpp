class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ret = 0;
        for (const vector<int>& account : accounts) {
            ret = std::max(ret, std::accumulate(account.begin(), account.end(), 0));
        }

        return ret;
    }
};
