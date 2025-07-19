class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        std::sort(players.begin(), players.end());
        std::sort(trainers.begin(), trainers.end());
        int m = players.size(), n = trainers.size();

        int ret = 0;
        for (int i = 0, j = 0; i < m && j < n;) {
            if (players[i] <= trainers[j]) {
                ++ret;
                ++i, ++j;
            }
            else {
                ++j;
            }
        }

        return ret;
    }
};
