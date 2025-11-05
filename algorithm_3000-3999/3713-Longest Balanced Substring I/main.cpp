class Solution {
public:
    int longestBalanced(string s) {
        int ret = 0;
        for (int i = 0, n = s.size(); i < n; ++i) {
            unordered_map<char, int> char2cnt;
            unordered_map<int, int> cnt2cnt;
            for (int j = i; j < n; ++j) {
                char c = s[j];
                int& cnt = char2cnt[c];
                --cnt2cnt[cnt];
                ++cnt;
                ++cnt2cnt[cnt];
                if (cnt2cnt[cnt] == char2cnt.size()) {
                    ret = std::max(ret, j - i + 1);
                }
            }
        }

        return ret;
    }
};
