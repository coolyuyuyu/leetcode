class Solution {
public:
    int countSubstrings(string s) {
        size_t cnt = s.size();

        vector<vector<bool>> dp(2, vector<bool>(s.size(), true));
        for (size_t len = 2; len <= s.size(); ++len) {
            for (size_t lft = 0, rht = lft + len - 1; rht < s.size(); ++lft, ++rht) {
                auto& cache = dp[(len % 2 == 0 ? 0 : 1)];
                cache[lft] = (s[lft] == s[rht]) && cache[lft + 1];
                if (cache[lft]) {
                    ++cnt;
                }
            }
        }

        return cnt;
    }
};
