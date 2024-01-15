class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> inDegrees;
        for (const auto& match : matches) {
            int winner = match[0], loser = match[1];
            inDegrees.emplace(winner, 0);
            ++inDegrees[loser];
        }

        vector<vector<int>> ret(2);
        for (const auto& [player, inDegree] : inDegrees) {
            switch (inDegree) {
            case 0:
                ret[0].push_back(player);
                break;
            case 1:
                ret[1].push_back(player);
                break;
            }
        }

        return ret;
    }
};
