class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        for (size_t r = 0; r < words.size(); ++r) {
            if (words.size() <words[r].size()) {
                return false;
            }
            for (size_t c = 0; c < words[r].size(); ++c) {
                if (words[r][c] != words[c][r]) {
                    return false;
                }
            }
        }

        return true;
    }
};
