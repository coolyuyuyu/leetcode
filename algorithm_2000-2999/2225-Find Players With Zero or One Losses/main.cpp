class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> inDegrees;
        for (const auto& match : matches) {
            inDegrees.emplace(match[0], 0);
            ++inDegrees[match[1]];
        }

        vector<vector<int>> ans(2);
        for (const auto& p : inDegrees) {
            if (p.second == 0) {
                ans[0].push_back(p.first);
            }
            else if (p.second == 1) {
                ans[1].push_back(p.first);
            }
        }

        return ans;
    }
};
