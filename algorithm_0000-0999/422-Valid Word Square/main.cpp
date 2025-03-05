class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        for (int r = 0; r < words.size(); ++r) {
            for (int c = 0; c < words[r].size(); ++c) {
                if (c >= words.size() ||
                    r >= words[c].size() ||
                    words[r][c] != words[c][r]) {
                    return false;
                }
            }
        }

        return true;
    }
};
