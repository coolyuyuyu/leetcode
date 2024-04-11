class Solution {
public:
    long long countSubstrings(string s, char c) {
        int cnt = std::count(s.begin(), s.end(), c);
        return cnt * (cnt - 1);
    }
};
