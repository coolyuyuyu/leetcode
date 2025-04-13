class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        std::sort(s.begin(), s.begin() + n / 2);

        for (int i = 0; i < n / 2; ++i) {
            s[n - 1 - i] = s[i];
        }

        return s;
    }
};
