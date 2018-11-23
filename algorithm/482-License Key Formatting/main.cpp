class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string ans;
        for (auto itr = S.rbegin(); itr != S.rend(); ++itr) {
            if (*itr == '-') {
                continue;
            }

            if (ans.size() % (K + 1) == K) {
                ans.push_back('-');
            }

            ans.push_back(toupper(*itr));
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};