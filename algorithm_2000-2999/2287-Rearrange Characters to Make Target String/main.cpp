class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> cnt1(26, 0), cnt2(26, 0);
        for (char c : s) {
            ++cnt1[c - 'a'];
        }
        for (char c : target) {
            ++cnt2[c - 'a'];
        }

        int ret = INT_MAX;
        for (int i = 0; i < 26; ++i) {
            if (cnt2[i] == 0) { continue; }
            ret = std::min(ret, cnt1[i] / cnt2[i]);
        }

        return ret;
    }
};
