class Solution {
public:
    int minChanges(string s) {
        int n = s.size();

        int ret = 0;
        for (int i = 1; i < n; i += 2) {
            if (s[i - 1] == '0' && s[i] == '1') {
                ret += 1;
            }
            else if (s[i - 1] == '1' && s[i] == '0') {
                ret += 1;
            }
        }

        return ret;
    }
};
