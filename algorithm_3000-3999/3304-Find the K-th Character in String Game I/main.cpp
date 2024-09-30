class Solution {
public:
    char kthCharacter(int k) {
        --k;

        string s = "a";
        while (k >= s.size()) {
            for (int i = 0, n = s.size(); i < n; ++i) {
                s += 'a' + ((s[i] - 'a') + 1) % 26;
            }
        }

        return s[k];
    }
};
