class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string, int> cnts;
        for (const auto& response : responses) {
            unordered_set<string> s(response.begin(), response.end());
            for (const string& str : s) {
                ++cnts[str];
            }
        }

        int maxCnt = 0;
        string ret;
        for (const auto& [str, cnt] : cnts) {
            if (cnt > maxCnt) {
                maxCnt = cnt;
                ret = str;
            }
            else if (cnt == maxCnt && str < ret) {
                ret = str;
            }
        }

        return ret;
    }
};
