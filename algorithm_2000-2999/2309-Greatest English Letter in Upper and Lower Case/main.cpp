class Solution {
public:
    string greatestLetter(string s) {
        vector<pair<bool, bool>> flag(26, {false, false});
        for (char c : s) {
            if (islower(c)) {
                flag[c - 'a'].first = true;
            }
            else {
                flag[c - 'A'].second = true;
            }
        }

        for (int i = 26; 0 < i--;) {
            if (flag[i].first && flag[i].second) {
                return string(1, 'A' + i);
            }
        }
        return "";
    }
};
