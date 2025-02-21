class Solution {
public:
    void reverseWords(vector<char>& s) {
        std::reverse(s.begin(), s.end());
        for (int i = 0, pre = 0, n = s.size(); i <= n; ++i) {
            if (i == n || s[i] == ' ') {
                std::reverse(s.begin() + pre, s.begin() + i);
                pre =  i + 1;
            }
        }
    }
};
