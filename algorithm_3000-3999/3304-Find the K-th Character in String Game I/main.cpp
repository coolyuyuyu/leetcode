class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while (s.size() < k) {
            for (int i = 0, n = s.size(); i < n; ++i) {
                s += ('a' + (s[i] - 'a' + 1) % 26);
            }
        }

        return s[k - 1];
    }
};
