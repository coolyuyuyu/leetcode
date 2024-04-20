class Solution {
public:
    string getSmallestString(string s, int k) {
        int n = s.size();

        std::function<int(char, char)> distance = [](char a, char b) {
            if (a > b) {
                std::swap(a, b);
            }
            return std::min(b - a, a + 26 - b);
        };

        for (int i = 0; i < n && k > 0; ++i) {
            int d = distance(s[i], 'a');
            if (d <= k) {
                s[i] = 'a';
                k -= d;
            }
            else {
                s[i] -= k;
                k = 0;
            }
        }

        return s;
    }
};
