class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ret(s.size() + spaces.size(), ' ');
        for (int i = 0, j = 0, k = 0; k < ret.size(); ++k) {
            if (j < spaces.size() && spaces[j] + j == k) {
                ++j;
            }
            else {
                ret[k] = s[i++];
            }
        }

        return ret;
    }
};
