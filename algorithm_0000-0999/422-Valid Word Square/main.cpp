class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        for (int r = 0; r < words.size(); ++r) {
            if (words.size() < words[r].size()) {
                return false;
            }
            for (int c = 0; c < words[r].size(); ++c) {
                if (words[r][c] != words[c][r]) {
                    return false;
                }
            }
        }

        return true;
    }
};
