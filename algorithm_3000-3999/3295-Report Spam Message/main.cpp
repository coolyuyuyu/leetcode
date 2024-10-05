class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> banned(bannedWords.begin(), bannedWords.end());

        int cnt = 0;
        for (const string& s : message) {
            if (banned.find(s) != banned.end()) {
                if (++cnt >= 2) {
                    return true;
                }
            }
        }

        return false;
    }
};
