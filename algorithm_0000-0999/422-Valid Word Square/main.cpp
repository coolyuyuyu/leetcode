class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        for (size_t i = 0; i < words.size(); ++i) {
            if (words.size() < words[i].size()) {
                return false;
            }
            for (size_t j = i + 1; j < words[i].size(); ++j) {
                if (words[i][j] != words[j][i]) {
                    return false;
                }
            }
            for (size_t j = words[i].size(); j < words.size(); ++j) {
                if (i < words[j].size()) {
                    return false;
                }
            }
        }

        return true;
    }
};
