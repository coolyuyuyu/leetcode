class Solution {
public:
    int maxVowels(string s, int k) {
        auto isvowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; 
        };

        int ret = 0;
        for (int i = 0, cnt = 0; i < s.size(); ++i) {
            if (k <= i) {
                cnt -= (isvowel(s[i - k]) ? 1 : 0);
            }
            cnt += (isvowel(s[i]) ? 1 : 0);

            ret = std::max(ret, cnt);
        }

        return ret;
    }
};
