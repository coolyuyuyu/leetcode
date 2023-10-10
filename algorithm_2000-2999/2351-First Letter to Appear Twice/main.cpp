class Solution {
public:
    char repeatedCharacter(string s) {
        vector<bool> exist(26, false);
        for (char c : s) {
            if (exist[c - 'a']) {
                return c;
            }
            else {
                exist[c - 'a'] = true;
            }
        }

        return '\0';
    }
};
