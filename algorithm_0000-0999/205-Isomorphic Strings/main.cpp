class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> table(256, 0);
        vector<bool> done(256, false);
        for (int i = 0; i < s.size(); ++i) {
            if (table[s[i]]) {
                if (table[s[i]] != t[i]) {
                    return false;
                }
            }
            else {
                if (done[t[i]]) {
                    return false;
                }
                done[t[i]] = true;
                table[s[i]] = t[i];
            }
        }

        return true;
    }
};
