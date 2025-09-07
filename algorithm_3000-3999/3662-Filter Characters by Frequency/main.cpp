class Solution {
public:
    string filterCharacters(string s, int k) {
        vector<int> cnts(26, 0);
        for (char c : s) {
            ++cnts[c - 'a'];
        }

        string ret;
        for (char c : s) {
            if (cnts[c - 'a'] < k) {
                ret += c;
            }
        }

        return ret;
    }
};
