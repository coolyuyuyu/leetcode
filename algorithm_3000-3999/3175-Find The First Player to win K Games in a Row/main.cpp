class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int i = 0;
        for (int j = 1, win = 0; j < skills.size(); ++j) {
            if (skills[i] > skills[j]) {
                ++win;
            }
            else {
                i = j;
                win = 1;
            }

            if (win == k) {
                break;
            }
        }

        return i;
    }
};
