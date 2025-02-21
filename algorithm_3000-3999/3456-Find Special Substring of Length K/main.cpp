class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        for (int i = 0, n = s.size(); i < n;) {
            int j = i + 1;
            while (j < n && s[i] == s[j]) {
                ++j;
            }
            if (j - i == k) {
                return true;
            }

            i = j;
        }

        return false;
    }
};
