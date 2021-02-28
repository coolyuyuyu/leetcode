class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        for (size_t i = 0; i < words.size(); ++i) {
            if (words.size() < words[i].size()) {
                return false;
            }

            for (size_t j = i + 1; j < words[i].size(); ++j) {
                if (words[j].size() < (i + 1)) {
                    return false;
                }

                if (words[i][j] != words[j][i]) {
                    return false;
                }
            }

            for (size_t k = words[i].size(); k < words.size(); ++k) {
                if (i < words[k].size()) {
                    return false;
                }
            }
        }

        return true;
    }
};